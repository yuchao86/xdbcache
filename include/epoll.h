/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _EPOLL_H
#define _EPOLL_H
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <error.h>


#define EV_IN  EPOLLIN
#define EV_OUT EPOLLOUT
#define EV_ERR EPOLLERR
#define EV_ET  EPOLLET

#include "Engine.h"
#include "Socket.h"
#include <stdint.h>
int32_t  epoll_init(engine_t);
int32_t  epoll_loop(engine_t,int32_t timeout);
int32_t  epoll_register(engine_t,socket_t);
int32_t  epoll_unregister(engine_t,socket_t);
#endif
