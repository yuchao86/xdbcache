/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _LOCAL_POOL_H
#define _LOCAL_POOL_H
#include <stdint.h>
typedef struct local_pool *local_pool_t;
#include "allocator.h"


extern struct allocator* local_pool_create(void*,int32_t size);
extern void   local_pool_destroy(struct allocator **);

extern void *local_pool_alloc(struct allocator*,int32_t);
extern void  local_pool_dealloc(struct allocator*,void*);


#endif
