/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */


#ifndef _DBTYPE_H
#define _DBTYPE_H
#include <stdint.h>
#include "link_list.h"
#include "refbase.h"

/*
* 定义内存数据库value支持的类型
*/
enum
{
	DB_INT8 = 0,
	DB_INT16,
	DB_INT32,
	DB_INT64,
	DB_DOUBLE,
	DB_STRING,
	DB_BINARY,
	DB_LIST,
	DB_ARRAY,	
};
struct basetype;
typedef struct basetype
{
	struct refbase ref;
	int8_t type;
	union{
		void  *data;
		struct link_list *l;
		struct basetype **array_data;
	};
}basetype,*basetype_t;

struct db_type_string
{
	struct basetype base;
	int32_t size;
};

struct db_type_binary
{
	struct basetype base;
	int32_t size;
};

basetype_t  basetype_create_int8(int8_t init);
basetype_t  basetype_create_int16(int16_t init);
basetype_t  basetype_create_int32(int32_t init);
basetype_t  basetype_create_int64(int64_t init);
basetype_t  basetype_create_double(double init);
basetype_t  basetype_create_str(const char *init);
basetype_t  basetype_create_bin(void *init,int32_t size);

int8_t      basetype_get_int8(basetype_t);
int16_t     basetype_get_int16(basetype_t);
int32_t     basetype_get_int32(basetype_t);
int64_t     basetype_get_int64(basetype_t);
double      basetype_get_double(basetype_t);
const char *basetype_get_str(basetype_t);
void *      basetype_get_bin(basetype_t,int32_t*); 

void        basetype_set_int8(basetype_t,int8_t);
void        basetype_set_int16(basetype_t,int16_t);
void        basetype_set_int32(basetype_t,int32_t);
void        basetype_set_int64(basetype_t,int64_t);
void        basetype_set_double(basetype_t,double);
void        basetype_set_str(basetype_t,const char*);
void        basetype_set_bin(basetype_t,void *,int32_t);

basetype_t  basetype_acquire(basetype_t,basetype_t);
void        basetype_release(basetype_t*);

#endif
