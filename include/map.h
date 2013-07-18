/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _MAP_H
#define _MAP_H
#include <stdint.h>
#include "iterator.h"
typedef struct map_iter
{
	struct base_iterator base;
	void *node;
}map_iter;

//����Ϊmap�洢���������Ͷ�����ʵ�ֵĽӿ�
struct interface_map_container
{
	map_iter (*insert)(struct interface_map_container*,void*,void*);
	map_iter (*erase)(struct interface_map_container*,map_iter);
	void     (*remove)(struct interface_map_container* rb,void*);
	map_iter (*find)(struct interface_map_container* rb,void *);
	map_iter (*begin)(struct interface_map_container* rb);
	map_iter (*end)(struct interface_map_container* rb);
	int32_t  (*size)(struct interface_map_container*);
	int32_t  (*empty)(struct interface_map_container*);
	void     (*destroy)(struct interface_map_container**);
};

//��ȷ���0,С�ڷ���-1,���ڷ���1
typedef int32_t (*comp)(void*,void*);
typedef struct map *map_t;

//����һ��map,������һ��������0,��Ĭ��ʹ�ú����
map_t    map_create(uint16_t key_size,uint16_t val_size,comp _comp,struct interface_map_container*);
void     map_destroy(map_t*);

inline extern map_iter map_insert(map_t,void*,void*);
inline extern map_iter map_erase(map_t,map_iter);
inline extern void     map_remove(map_t,void*);
inline extern map_iter map_find(map_t,void *);
inline extern map_iter map_begin(map_t);
inline extern map_iter map_end(map_t);
inline extern int32_t  map_size(map_t);
inline extern int32_t  map_empty(map_t);

#ifndef MAP_CREATE
#define MAP_CREATE(KEY_TYPE,VAL_TYPE,COMP,CONTAINER)\
	map_create(sizeof(KEY_TYPE),sizeof(VAL_TYPE),COMP,CONTAINER)
#endif

#ifndef MAP_INSERT
#define MAP_INSERT(KEY_TYPE,VAL_TYPE,MAP,KEY,VAL)\
	({  map_iter it;KEY_TYPE __key = KEY;VAL_TYPE __val = VAL;\
       do it = map_insert(MAP,&__key,&__val);\
       while(0);\
       it;})		
#endif

#ifndef MAP_REMOVE
#define MAP_REMOVE(KEY_TYPE,MAP,KEY)\
	{ KEY_TYPE __key = KEY;map_remove(MAP,&__key);}
#endif

#ifndef MAP_FIND
#define MAP_FIND(KEY_TYPE,MAP,KEY)\
   ({  map_iter it;KEY_TYPE __key = KEY;\
       do it = map_find(MAP,&__key);\
       while(0);\
       it;})	
#endif

#endif