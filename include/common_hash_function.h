/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
 /**
  *	lookup8.c, by Bob Jenkins, January 4 1997, Public Domain.
  *	hash(), and mix() are externally useful functions.
  *	You can use this free for any purpose.  It has no warranty.
  */

#ifndef __COMMON_HASH_FUNCTION__
#define __COMMON_HASH_FUNCTION__

/**
 *	common hash function
 *	it's from http://burtleburtle.net/bob/c/lookup8.c
 *	and copy right is Public Domain
 */

uint64_t burtle_hash(uint8_t *k,uint64_t length,uint64_t level);

#endif	/**__COMMON_HASH_FUNCTION_ */