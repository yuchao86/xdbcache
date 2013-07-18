/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
//内存分配器接口类
#ifndef _ALLOCATOR_H
#define _ALLOCATOR_H
#include <stdint.h>
//内存分配器接口类
typedef struct allocator
{
	void* (*_alloc)(struct allocator*,int32_t);
	void (*_dealloc)(struct allocator*,void*);
	void (*_destroy)(struct allocator**);
}*allocator_t;

#ifndef IMPLEMEMT
#define IMPLEMEMT(SUPER_CLASS) struct SUPER_CLASS super_class
#endif

#ifndef ALLOC
#define ALLOC(ALLOCATOR,SIZE)\
   ({ void *__result;\
       do \
	   if(ALLOCATOR)\
	     __result = ((struct allocator*)ALLOCATOR)->_alloc(ALLOCATOR,SIZE);\
	   else\
	     __result = calloc(1,SIZE);\
	   while(0);\
       __result;})
#endif

#ifndef FREE	
#define FREE(ALLOCATOR,PTR)\
   ({\
       do \
	   if(ALLOCATOR)\
	     ((struct allocator*)ALLOCATOR)->_dealloc(ALLOCATOR,PTR);\
	   else\
	     free(PTR);\
	   while(0);\
		})
#endif

#ifndef DESTROY
#define DESTROY(ALLOCATOR)\
	((struct allocator*)(*(ALLOCATOR)))->_destroy((ALLOCATOR))
#endif
	
#endif
