/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */

#ifndef _SPINLOCK_H
#define _SPINLOCK_H

#include <pthread.h>
#include "atomic.h"

typedef struct spinlock *spinlock_t;

spinlock_t spin_create();
void spin_destroy(spinlock_t*);
inline int32_t spin_lock(spinlock_t);
inline int32_t spin_unlock(spinlock_t);

/*
static inline int32_t
atomic_cmp_set(int32_t *lock, int32_t old,
    int32_t set)
{
    int8_t  res;
	//"    cmpxchgq  %3, %1;   "
    __asm__ volatile (

    "lock;"
    "    cmpxchgl  %3, %1;   "
    "    sete      %0;       "

    : "=a" (res) : "m" (*lock), "a" (old), "r" (set) : "cc", "memory");

    return res;
}
*/
#endif
