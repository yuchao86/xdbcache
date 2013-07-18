/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */


#ifndef _GLOBAL_TABLE_H
#define _GLOBAL_TABLE_H
#include <string.h>
#include "dbtype.h"
#include "data_struct.h"
#include "common_hash_function.h"

typedef struct global_table *global_table_t;


global_table_t global_table_create(int32_t initsize);
void           global_table_destroy(global_table_t*);


basetype_t     global_table_find(global_table_t,const char *key,uint64_t hash_code);
basetype_t     global_table_remove(global_table_t,const char *key,uint64_t hash_code);
basetype_t     global_table_insert(global_table_t,const char *key,basetype_t a,uint64_t hash_code);

/*
db_element_t   global_table_find(global_table_t,const char *key,uint64_t hash_code);
db_element_t   global_table_remove(global_table_t,const char *key,uint64_t hash_code);
db_array_t     global_table_add_array(global_table_t,const char *key,db_array_t a,uint64_t hash_code);
db_list_t      global_table_add_list(global_table_t,const char *key,db_list_t l,uint64_t hash_code);
*/


static inline  uint64_t global_hash(const char *key)
{
	return burtle_hash((uint8_t*)key,strlen(key),1);
}

void           global_table_shrink(global_table_t,uint32_t maxtime);

int64_t        global_table_size(global_table_t);

#endif
