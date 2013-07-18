/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
/**
 *	һЩ�׽ӿ�API�İ�װ����.
 */

#ifndef _SOCK_WRAPPER_H
#define _SOCK_WRAPPER_H

#include	<sys/types.h>	/* basic system data types */
#include	<sys/socket.h>	/* basic socket definitions */
#include	<sys/time.h>	/* timeval{} for select() */
#include	<time.h>		/* timespec{} for pselect() */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */
#include	<arpa/inet.h>	/* inet(3) functions */
#include	<errno.h>
#include	<fcntl.h>		/* for nonblocking */
#include	<netdb.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>	/* for S_xxx file mode constants */
#include	<sys/uio.h>		/* for iovec{} and readv/writev */
#include	<unistd.h>
#include	<sys/wait.h>
#include	<sys/un.h>		/* for Unix domain sockets */
#include    <net/if.h>
#include    <sys/ioctl.h>
#include    <netinet/tcp.h>
#include    <fcntl.h>
#include    <stdint.h>

#ifndef TEMP_FAILURE_RETRY
#define TEMP_FAILURE_RETRY(expression)\
   ({ long int __result;\
       do __result = (long int)(expression);\
       while(__result == -1L&& errno == EINTR);\
       __result;})
#endif

enum sock_family
{
	INET = AF_INET,
	INET6 = AF_INET6,
	LOCAL = AF_LOCAL,
	ROUTE = AF_ROUTE,
#ifdef _LINUX
	KEY = AF_KEY,
#endif
};

enum sock_type
{
	STREAM = SOCK_STREAM,//��Э��
	DGRAM  = SOCK_STREAM,//���ݱ�Э��
	SEQPACKET = SOCK_SEQPACKET,
	RAW = SOCK_RAW,//ԭʼ�׽ӿ�
};

enum sock_protocol
{
	TCP = IPPROTO_TCP,
	UDP = IPPROTO_UDP,
	SCTP = IPPROTO_SCTP,
};

//typedef sock_wrapper *socket_t;
#include "KendyNet.h"
HANDLE  OpenSocket(int32_t family,int32_t type,int32_t protocol);

//close connection
int32_t CloseSocket(HANDLE);

//release handle
void ReleaseSocket(HANDLE);

int32_t Connect(HANDLE sock,const struct sockaddr *servaddr,socklen_t addrlen);

/**
 * brief: �����׽���,��������ĶԶ˽�������.
 * para:  
 *        ip:�Զ˵�IP��ַ
 *        port:�Զ˶˿�
 *        servaddr:
 *        retry: ���connectʧ���Ƿ����³���,ֱ�����ӳɹ��ŷ��� 
 * return: >0 �׽���,-1,ʧ��.
 */
HANDLE Tcp_Connect(const char *ip,uint16_t port,struct sockaddr_in *servaddr,int32_t retry);

int32_t Bind(HANDLE sock,const struct sockaddr *myaddr,socklen_t addrlen);

int32_t Listen(HANDLE sock,int32_t backlog);

/*
 * brief: �����׽���,����,Ȼ���ڴ��׽����ϼ���.
 *
 */
HANDLE Tcp_Listen(const char *ip,uint16_t port,struct sockaddr_in *servaddr,int32_t backlog);


HANDLE Accept(HANDLE,struct sockaddr *sa,socklen_t *salen);

/*
 * brief: ��ȡԶ�����ӵ�IP,�˿ں�.
 */
int32_t getRemoteAddrPort(HANDLE sock,char *buf,uint16_t *port);
int32_t getLocalAddrPort(HANDLE sock,struct sockaddr_in *remoAddr,socklen_t *len,char *buf,uint16_t *port);

/*
ssize_t write_fd(int fd,void *ptr,size_t nbytes,int sendfd);

int create_un_execl(const char *path,const char *child);

ssize_t read_fd(int fd,void *ptr,size_t nbytes,int *recvfd);
*/

struct hostent *Gethostbyaddr(const char *ip,int32_t family);

int32_t setNonblock(HANDLE sock);

#endif



