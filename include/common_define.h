/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _COMMON_DEFINE_H
#define _COMMON_DEFINE_H

enum
{
	MUTIL_THREAD = 1,
	SINGLE_THREAD = 0,
};

//消息类型定义
enum
{
	MSG_RPACKET = 0,
	MSG_WPACKET,
	MSG_NEW_CONNECTION,
	MSG_DISCONNECTED,
	MSG_ACTIVE_CLOSE,
	MSG_SEND_BLOCK,
	MSG_SET_RECV_TIMEOUT,
	MSG_SET_SEND_TIMEOUT,
	MSG_USER_TIMER_TIMEOUT,
	MSG_END,
};

#endif
