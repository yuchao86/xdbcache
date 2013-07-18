/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _SOCKETWRAPPER_H
#define _SOCKETWRAPPER_H
#include <stdint.h>
#include "double_link.h"
#include "KendyNet.h"

typedef struct socket_wrapper
{
	struct double_link_node dnode;
	volatile int32_t status;//0:δ����;1:����;
	struct engine  *engine;
	volatile int32_t isactived;//��ǰ�Ƿ���actived�б���
	volatile int32_t readable;
	volatile int32_t writeable;
	int32_t fd;
	HANDLE handle;
	struct link_list *pending_send;//��δ����ķ�����
	struct link_list *pending_recv;//��δ����Ķ�����
	void (*OnRead)(int32_t,st_io*);
	void (*OnWrite)(int32_t,st_io*);
	void (*OnClear_pending_io)(st_io*);
}*socket_t;


void on_read_active(socket_t);
void on_write_active(socket_t);
int32_t  Process(socket_t);
socket_t create_socket();
void free_socket(socket_t*);

int32_t raw_send(socket_t s,st_io *io_req,uint32_t *err_code);
int32_t raw_recv(socket_t s,st_io *io_req,uint32_t *err_code);

#endif
