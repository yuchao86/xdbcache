/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
#ifndef _TLS_H
#define _TLS_H
#include <pthread.h>
#include <stdint.h>
void init_tls();
void clear_tls();
void *get_tls_data(int32_t);
void set_tls_data(int32_t,void*);

#endif
	