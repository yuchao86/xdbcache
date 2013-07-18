/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
#ifndef _ACCEPTOR_H
#define _ACCEPTOR_H
#include <stdint.h>

typedef struct acceptor* acceptor_t;
typedef void (*on_accept)(HANDLE,void*ud);

acceptor_t create_acceptor();

HANDLE    add_listener(acceptor_t,const char *ip,uint32_t port,on_accept,void*);
void      rem_listener(acceptor_t,HANDLE);

void       destroy_acceptor(acceptor_t*);
void       acceptor_run(acceptor_t,int32_t ms);

#endif
