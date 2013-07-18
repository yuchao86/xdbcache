/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */


#ifndef _DATA_STRUCT_H
#define _DATA_STRUCT_H
#include <stdint.h>
#include "refbase.h"
#include "dbtype.h"
#include "link_list.h"

/*
* 内存数据库value支持的两个容器类型
*/

typedef struct db_array
{
	basetype base;
	int32_t size;
}*db_array_t;


basetype_t db_array_create(int32_t size);
void       db_array_clear(db_array_t);//clear the data


basetype_t db_array_get(db_array_t,int32_t index);
void       db_array_set(db_array_t,int32_t index,basetype_t);

struct db_node
{
	list_node  next;
	basetype_t element;
};

typedef struct db_list
{
	basetype base;
	int32_t size;
}*db_list_t;

basetype_t db_list_create();
int32_t    db_list_append(db_list_t,basetype_t);
basetype_t db_list_pop(db_list_t);
int32_t    db_list_size(db_list_t);
int8_t     db_list_shrink(db_list_t,uint32_t maxtime);

#endif	
