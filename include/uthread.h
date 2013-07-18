/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
#ifndef _UTHREAD_H
#define _UTHREAD_H
#include <stdint.h>
typedef struct uthread *uthread_t;

uthread_t uthread_create(uthread_t parent,void*stack,uint32_t stack_size,void*(*fun)(void*));
void uthread_destroy(uthread_t*);
void* __attribute__((regparm(3))) uthread_switch(uthread_t from,uthread_t to,void *para);



#endif
