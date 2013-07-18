/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _CONNECTOR_H
#define _CONNECTOR_H

#include <stdint.h>
typedef struct connector *connector_t;
typedef void (*on_connect)(HANDLE,const char *ip,int32_t port,void*ud);

connector_t connector_create();
void        connector_destroy(connector_t*);
int32_t         connector_connect(connector_t,const char *ip,uint32_t port,on_connect,void *ud,uint32_t ms);
void        connector_run(connector_t,uint32_t ms);

#endif