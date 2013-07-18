/**
 *	Xdbcache
 *	���ݿ���ٻ���
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _TIMING_WHEEL_H
#define _TIMING_WHEEL_H
#include <stdint.h>
//��ʱ����
typedef struct WheelItem   *WheelItem_t;
typedef struct TimingWheel *TimingWheel_t;
typedef void   (*TimingWheel_callback)(TimingWheel_t,void*,uint32_t);
typedef void   (*WheelItem_OnDestroy)(WheelItem_t);
/*
* precision:��С����,�Ժ���Ϊ��λ
* max:����ܶ�����ʱ��,�Ժ���Ϊ��λ
*/
extern TimingWheel_t CreateTimingWheel(uint32_t precision,uint32_t max);
extern void DestroyTimingWheel(TimingWheel_t*);
extern int32_t  RegisterTimer(TimingWheel_t,WheelItem_t,uint32_t timeout);
extern void  UnRegisterTimer(/*TimingWheel_t,*/WheelItem_t);
extern int32_t  UpdateWheel(TimingWheel_t,uint32_t now);
extern WheelItem_t CreateWheelItem(void *ud,TimingWheel_callback callback,WheelItem_OnDestroy ondestroy);
extern void DestroyWheelItem(WheelItem_t*);
extern void *GetUserData(WheelItem_t);
#endif
