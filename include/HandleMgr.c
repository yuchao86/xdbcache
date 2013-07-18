/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#include "HandleMgr.h"

HANDLE	NewSocketWrapper()
{
	return (HANDLE)create_socket();
}


inline static int RemoveBinding(engine_t e, socket_t sock)
{
	return e ? e->UnRegister(e,sock) : -1;
}

void  ReleaseSocketWrapper(HANDLE handle)
{
	socket_t s = (socket_t)handle;
	double_link_remove((struct double_link_node*)s);
	if(s->engine)
		RemoveBinding(s->engine,s);
	close(s->fd);
	if(s->OnClear_pending_io)
	{
		list_node *tmp;
		while((tmp = link_list_pop(s->pending_send))!=NULL)
			s->OnClear_pending_io((st_io*)tmp);
		while((tmp = link_list_pop(s->pending_recv))!=NULL)
			s->OnClear_pending_io((st_io*)tmp);
	}	
	free_socket(&s);
} 

HANDLE	NewEngine()
{
	return (HANDLE)create_engine();
}

void  ReleaseEngine(HANDLE handle)
{
	engine_t e = (engine_t)handle;
	free_engine(&e);
}
