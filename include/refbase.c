/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#include "refbase.h"

void ref_increase(struct refbase *r)
{
	if(r->mt)
		ATOMIC_INCREASE(&r->refcount);
	else
		++r->refcount;
}

void ref_decrease(struct refbase *r)
{
	if(r->mt)
	{
		if(ATOMIC_DECREASE(&r->refcount) <= 0 && r->destroyer)
			r->destroyer(r);
	}
	else
	{
		if(--r->refcount <= 0 && r->destroyer)
			r->destroyer(r);
	}
}

