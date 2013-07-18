/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _ITERATOR_H
#define _ITERATOR_H

struct base_iterator
{
	void   (*next)(struct base_iterator*);
	void   (*get_key)(struct base_iterator*,void*);
	void   (*get_val)(struct base_iterator*,void*);
	void   (*set_val)(struct base_iterator*,void*);
	int8_t (*is_equal)(struct base_iterator*,struct base_iterator*);
};

/*
#ifndef IT_NEXT
#define IT_NEXT(IT_TYPE,ITER)\
   ({ IT_TYPE __result;\
       do ITER.base.next((struct base_iterator*)&ITER,(struct base_iterator*)&__result);\
       while(0);\
       __result;})
#endif*/

#ifndef IT_NEXT
#define IT_NEXT(ITER)\
	ITER.base.next((struct base_iterator*)&ITER)
#endif

#ifndef IT_EQ
#define IT_EQ(IT1,IT2)\
	IT1.base.is_equal((struct base_iterator*)&IT1,(struct base_iterator*)&IT2)
#endif

#ifndef IT_GET_KEY
#define IT_GET_KEY(TYPE,ITER)\
   ({ TYPE __result;\
       do ITER.base.get_key((struct base_iterator*)&ITER,&__result);\
       while(0);\
       __result;})
#endif

#ifndef IT_GET_VAL
#define IT_GET_VAL(TYPE,ITER)\
   ({ TYPE __result;\
       do ITER.base.get_val((struct base_iterator*)&ITER,&__result);\
       while(0);\
       __result;})
#endif

#ifndef IT_SET_VAL
#define IT_SET_VAL(TYPE,ITER,VAL)\
	{TYPE __val=VAL;ITER.base.set_val((struct base_iterator*)&ITER,&__val);}
#endif

#endif