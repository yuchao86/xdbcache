/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _MINHEAP_H
#define _MINHEAP_H
#include <stdint.h>
struct heapele
{
	int32_t index;//index in minheap;
};

typedef struct minheap
{
	int32_t size;
	int32_t max_size;
	int8_t (*less)(struct heapele*l,struct heapele*r);//if l < r return 1,else return 0	
	struct heapele** data;
}*minheap_t;


minheap_t minheap_create(int32_t size,int8_t (*)(struct heapele*l,struct heapele*r));
void minheap_destroy(minheap_t*);
typedef void (*clear_fun)(struct heapele*);
void minheap_clear(minheap_t,clear_fun);

void minheap_remove(minheap_t,struct heapele*);
void minheap_change(minheap_t,struct heapele*);
void minheap_insert(minheap_t,struct heapele*);

//return the min element
struct heapele* minheap_min(minheap_t);

//return the min element and remove it
struct heapele* minheap_popmin(minheap_t);
#endif
