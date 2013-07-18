/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _KENDYNET_H
#define _KENDYNET_H
#include <stdint.h>
#include "link_list.h"
//����ϵͳ֧�ֵ�����׽��ֺ�engine������
#define MAX_ENGINE 64
#define MAX_SOCKET 4096

/*IO�������ɶ���ʹ�õĽṹ*/
typedef struct
{
	LIST_NODE;
	struct iovec *iovec;
	int32_t    iovec_count;
	uint32_t err_code;
}st_io;


//��ʼ������ϵͳ
int32_t      InitNetSystem();

typedef void* HANDLE;
#ifndef INVAILD_HANDLE
#define INVAILD_HANDLE NULL
#endif
struct block_queue;

//recv�������ʱcallback
typedef void (*OnRead)(int32_t,st_io*);
//send�������ʱcallback
typedef void (*OnWrite)(int32_t,st_io*);
//���ӹر�ʱ,������δ��ɵ�����ִ�е�callback
typedef void (*OnClear_pending)(st_io*);

HANDLE   CreateEngine();
void     CloseEngine(HANDLE);
int32_t  EngineRun(HANDLE,int32_t timeout);
int32_t  Bind2Engine(HANDLE,HANDLE,OnRead,OnWrite,OnClear_pending);

/**
*  ����ִ��IO����,����ɹ����ؽ��,
*  ���򷵻�-1,err_code == EAGAIN,���׽��ֱ�����ʱ����������������󣬲��ص�ע��ĺ���
*/
int32_t Recv(HANDLE,st_io*,uint32_t *err_code);
int32_t Send(HANDLE,st_io*,uint32_t *err_code);

/**
* Ͷ�������ڽ�����ĳ��ʱ������������������󣬲��ص�ע��ĺ���
*/
int32_t Post_Recv(HANDLE,st_io*);
int32_t Post_Send(HANDLE,st_io*);

//int32_t WSASend(HANDLE,st_io*,int32_t flag,uint32_t *err_code);
//int32_t WSARecv(HANDLE,st_io*,int32_t flag,uint32_t *err_code);

#endif
