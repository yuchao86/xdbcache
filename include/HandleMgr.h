/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _HANDLEMGR_H
#define _HANDLEMGR_H

#include "Net.h"
#include "epoll.h"
#include "Socket.h"
#include "Engine.h"
#include <stdint.h>
struct socket_wrapper;
struct engine;

static inline socket_t GetSocketByHandle(HANDLE handle)
{
	return (socket_t)handle;
}

static inline engine_t GetEngineByHandle(HANDLE handle)
{
	return (engine_t)handle;
}


extern HANDLE   NewEngine();
extern void     ReleaseEngine(HANDLE);

extern HANDLE   NewSocketWrapper();
extern void     ReleaseSocketWrapper(HANDLE);

#endif
