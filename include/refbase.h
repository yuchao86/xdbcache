/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _REFBASE_H
#define _REFBASE_H

#include <stdint.h>
#include "atomic.h"
struct refbase
{
	atomic_32_t refcount;
	uint8_t     mt;
	void (*destroyer)(void*);
};

inline void ref_increase(struct refbase*);
inline void ref_decrease(struct refbase*);


#endif
