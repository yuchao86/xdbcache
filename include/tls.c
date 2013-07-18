/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#include "tls.h"
#include "hash_map.h"
#include "common_hash_function.h"
#include "atomic.h"
#include "list.h"
#include "sync.h"

static atomic_8_t    is_init = 0;
static pthread_key_t thread_key;
static mutex_t       tls_mtx;
static list_t        tls_list;
  

void init_tls()
{
	if(!is_init)
	{
		 if(COMPARE_AND_SWAP(&is_init,0,1))
		 {
			pthread_key_create(&thread_key,0);
			tls_mtx = mutex_create();
			tls_list = list_create(sizeof(hash_map_t));
		 }
	}
}
void clear_tls()
{
	if(is_init)
	{
		if(COMPARE_AND_SWAP(&is_init,1,0) == 1)
		{
			pthread_key_delete(thread_key);
			mutex_lock(tls_mtx);
			list_iter it = list_begin(tls_list);
			list_iter end = list_end(tls_list);
			for( ; !IT_EQ(it,end); IT_NEXT(it))
			{
				hash_map_t h = IT_GET_VAL(hash_map_t,it);
				hash_map_destroy(&h);
			}
			mutex_unlock(tls_mtx);
			mutex_destroy(&tls_mtx);
			list_destroy(&tls_list);
		}
	}
}
static int32_t tls_hash_key_eq(void *a,void *b)
{
	int32_t *_a = (int32_t*)a;
	int32_t *_b = (int32_t*)b;
	return *_a == *_b;
}

static uint64_t tls_hash_func(void *key)
{
	return burtle_hash(key,sizeof(int32_t),1);
}

void *get_tls_data(int32_t key)
{
	hash_map_t h = (hash_map_t)pthread_getspecific(thread_key);
	if(!h)
	{
		h = hash_map_create(128,sizeof(key),sizeof(void*),tls_hash_func,tls_hash_key_eq);
		return NULL;
	}	
	hash_map_iter it = hash_map_find(h,(void*)&key);
	hash_map_iter end = hash_map_end(h);
	if(!IT_EQ(it,end))
		return IT_GET_VAL(void*,it);
	return NULL;
}
void set_tls_data(int32_t key,void *data)
{
	hash_map_t h = (hash_map_t)pthread_getspecific(thread_key);
	if(!h)
	{
		h = hash_map_create(128,sizeof(key),sizeof(void*),tls_hash_func,tls_hash_key_eq);
	}
	hash_map_iter it = hash_map_find(h,(void*)&key);
	hash_map_iter end = hash_map_end(h);
	if(IT_EQ(it,end))
		HASH_MAP_INSERT(int32_t,void*,h,key,data);
	else
		IT_SET_VAL(void*,it,data);
}
