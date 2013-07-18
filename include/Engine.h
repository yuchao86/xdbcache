/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _ENGINE_H
#define _ENGINE_H

#include <stdint.h>
#include "sync.h"
#include "link_list.h"
#include "double_link.h"
#include "Net.h"
struct socket_wrapper;
typedef struct engine
{
	int32_t  (*Init)(struct engine*);
	int32_t (*Loop)(struct engine*,int32_t timeout);
	int32_t  (*Register)(struct engine*,struct socket_wrapper*);
	int32_t  (*UnRegister)(struct engine*,struct socket_wrapper*);
	volatile int32_t status; /*0:�ر�״̬,1:����״̬*/
	int32_t poller_fd;
	struct epoll_event events[MAX_SOCKET];
	struct double_link *actived;
	//struct link_list *actived;//��������������Ҫ�������׽ӿ�
}*engine_t;

engine_t create_engine();
void   free_engine(engine_t *);

#endif
