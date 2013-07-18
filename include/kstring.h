/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _KSTRING_H
#define _KSTRING_H
#include <stdint.h>

typedef struct string *string_t;

struct vector;

extern string_t string_create(const char*str);
extern void   string_destroy(string_t*);
extern uint32_t string_size(string_t);
extern const char *string_c_str(string_t);

//��ֵ
extern string_t string_assign(string_t,string_t);
extern string_t string_assign_cstr(string_t,const char*);

//����
extern string_t string_cat(string_t,string_t);
extern string_t string_cat_cstr(string_t,const char*);

//����
extern const char* string_find(string_t,string_t);
extern const char* string_find_cstr(string_t,const char*);

//���,������ص�һ�������vector��
extern void string_split(string_t,struct vector*,const char *delimiters);

extern int32_t string_compare(string_t,string_t);

#endif
