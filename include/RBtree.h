/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _RBTREE_H
#define _RBTREE_H
#include <stdint.h>
typedef struct rbtree *rbtree_t;

typedef struct rbnode{
	struct rbnode *parent;
	struct rbnode *left;
	struct rbnode *right;
	void   *key;
	rbtree_t tree;
	uint8_t color;
}rbnode;

typedef int32_t (*cmp_function)(void*,void*);

typedef struct rbtree{
	rbnode *root;
	rbnode *nil;
	uint32_t size;
	cmp_function compare_function;
	rbnode  dummy;
}rbtree;

rbtree_t create_rbtree(cmp_function);
void     destroy_rbtree(rbtree_t *);
uint32_t rbtree_size(rbtree_t);
int8_t   rbtree_isempty(rbtree_t);
int8_t   rbtree_insert(rbtree_t,rbnode*);
rbnode*  rbtree_find(rbtree_t,void *key);
int8_t   rbtree_erase(rbnode*);
rbnode*  rbtree_remove(rbtree_t,void *key);
void     rbtree_check_vaild(rbtree_t rb);
rbnode*  rbtree_first(rbtree_t);
rbnode*  rbtree_last(rbtree_t);
rbnode*  rbnode_next(rbnode*);
rbnode*  rbnode_pre(rbnode*);
#endif

