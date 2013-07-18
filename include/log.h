/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */

/*
 * a sample log system	
*/

#ifndef _LOG_H
#define _LOG_H

#include <stdint.h>

typedef struct log *log_t;

int32_t	init_log_system();
void    close_log_system();

log_t   create_log(const char *);
int32_t log_write(log_t,const char*,int32_t level);

#endif
