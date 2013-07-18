/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */

//dbcache��˻����ӿ����

#ifdef USE_MYSQL
typedef MYSQL* DB_HANDLE;
#define INVAILD_DB_HANDLE NULL; 
#else
typedef int DB_HANDLE;
#endif
int      db_library_init();  //��ʼ��DB��
void     db_library_end();   //�ͷ�DB��

DB_HANDLE db_connect(const char *ip,unsigned int port,const char *usr,const char *pass,const char *db);  //����һ�������ݿ������
void      db_handle_close(DB_HANDLE*);//�ر�,�ͷ�����

//field��Ԫ����
struct field_metadata
{
	const char    *name; //�ֶ���
	unsigned int   max_length; //�ֶε���󳤶�(�ֽ�)
	unsigned short type;//�ֶ�����
	basetype_t     default_value;//Ĭ��ֵ
};

struct field_metadatas
{
	unsigned int size;
	struct field_metadata* _field_metadata;
};

typedef db_list_t result_set;

void     db_free_result_set(result_set*);//�ͷ�result_set

struct field_metadatas *db_get_table_metadata(DB_HANDLE,const char *table);//��ȡ���������ֶε�Ԫ����
result_set db_do_select(DB_HANDLE,const char *stmt);//ִ��select���
int      db_do_update(DB_HANDLE,const char *stmt);//ִ��update���
int      db_do_delete(DB_HANDLE,const char *stmt);//ִ��delete���

