/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
#ifndef _MAP_RBTREE_H
#define _MAP_RBTREE_H
#include <stdint.h>
#include "map.h"

typedef struct RBtree *RBtree_t;
extern RBtree_t RBtree_create(uint16_t,uint16_t,comp _comp);


struct interface_map_container;
extern void     RBtree_destroy(struct interface_map_container**);

///检查是否有违反红黑树性质
extern void      RBtree_check_vaild(RBtree_t);
#endif