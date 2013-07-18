/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
#ifndef _VECTOR_H
#define _VECTOR_H
#include <stdint.h>
typedef struct vector *vector_t;


vector_t vector_create(uint32_t val_size,uint32_t reserve_size);
vector_t vector_copy_create(vector_t);
void vector_copy(vector_t,vector_t);
void vector_clear(vector_t);

void vector_reserve(vector_t,uint32_t);

void vector_destroy(vector_t*);

uint32_t vector_size(vector_t);
uint32_t vector_capability(vector_t);
void vector_push_back(vector_t,void*);

#ifndef VECTOR_PUSH_BACK
#define VECTOR_PUSH_BACK(TYPE,VECTOR,VAL)\
	{TYPE __val = VAL;vector_push_back(VECTOR,&__val);}
#endif

void vector_get(vector_t,uint32_t,void*);
void vector_set(vector_t,uint32_t,void*);

void* vector_to_array(vector_t);

#ifndef VECTOR_TO_ARRAY
#define VECTOR_TO_ARRAY(TYPE,VECTOR)\
	({ TYPE *__result;\
       do __result = (TYPE*)vector_to_array(VECTOR);\
       while(0);\
       __result;})
#endif

#ifndef VECTOR_GET
#define VECTOR_GET(TYPE,VECTOR,I)\
   ({ TYPE __result;\
       do vector_get(VECTOR,I,&__result);\
       while(0);\
       __result;})
#endif

#ifndef VECTOR_SET
#define VECTOR_SET(TYPE,VECTOR,I,VAL)\
	{TYPE __val=VAL;vector_set(VECTOR,I,&__val);}
#endif




#endif