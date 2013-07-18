/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "sync.h"
#include "spinlock.h"

struct spinlock
{
	volatile   pthread_t  owner;
	int32_t    lock_count;
};



spinlock_t spin_create()
{
	spinlock_t sp = malloc(sizeof(*sp));
	sp->lock_count = 0;
#ifdef _MINGW_
	sp->owner.p = NULL;
    sp->owner.x = 0;	
#else
	sp->owner = 0;
#endif	
	return sp;
}

void spin_destroy(spinlock_t *sp)
{
	free(*sp);
	*sp = 0;
}

int32_t spin_lock(spinlock_t l)
{
#ifdef _MINGW_
	pthread_t tid = pthread_self();
	if(tid.p == l->owner.p)
	{
		++l->lock_count;
		return 0;
	}
	int32_t c,max;
	while(1)
	{
		if(l->owner.p == 0)
		{
			if(COMPARE_AND_SWAP(&(l->owner.p),0,tid.p) == 0)
				break;
		}
		__asm__ volatile("" : : : "memory");
		for(c = 0; c < (max = rand()%4096); ++c)
			__asm__("pause");		
	};
	++l->lock_count;
	return 0;
#else
	pthread_t tid = pthread_self();
	if(tid == l->owner)
	{
		++l->lock_count;
		return 0;
	}
	int32_t c,max;
	while(1)
	{
		if(l->owner == 0)
		{
			if(COMPARE_AND_SWAP(&(l->owner),0,tid) == 0)
				break;
		}
		__asm__ volatile("" : : : "memory");
		for(c = 0; c < (max = rand()%4096); ++c)
			__asm__("pause");		
	};
	++l->lock_count;
	return 0;
#endif	
}

int32_t spin_unlock(spinlock_t l)
{
#ifdef _MINGW_
	pthread_t tid = pthread_self();
	if(tid.p == l->owner.p)
	{
		--l->lock_count;
		if(l->lock_count == 0)
		{
			__asm__ volatile("" : : : "memory");
			l->owner.p = 0;
		}
		return 0;
	}
	return -1;
#else
	pthread_t tid = pthread_self();
	if(tid == l->owner)
	{
		--l->lock_count;
		if(l->lock_count == 0)
		{
			__asm__ volatile("" : : : "memory");
			l->owner = 0;
		}
		return 0;
	}
	return -1;
#endif
}

