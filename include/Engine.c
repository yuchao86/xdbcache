/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <assert.h>
#include "Net.h"
#include "epoll.h"
#include "Engine.h"
#include "link_list.h"


engine_t create_engine()
{
	engine_t e = malloc(sizeof(*e));
	if(e)
	{
		e->status = 1;
		e->Init = epoll_init;
		e->Loop = epoll_loop;
		e->Register = epoll_register;
		e->UnRegister = epoll_unregister;
		e->actived = (struct double_link*)calloc(1,sizeof(*e->actived));
		double_link_clear(e->actived);
	}
	return e;
}

void   free_engine(engine_t *e)
{
	assert(e);
	assert(*e);
	free((*e)->actived);
	free(*e);
	*e = 0;
}
