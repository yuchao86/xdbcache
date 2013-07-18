/**
 *	Xdbcache
 *	数据库高速缓存
 *	@E-Mail:yuchao86@gmail.com
 *	@author YuChao
 *	@Copyright under GNU General Public License All rights reserved.
 *	@date 2013-07-16
 *	@see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _TIMER_H
#define _TIMER_H
#include <stdint.h>
#define MAX_TIMER 4096

typedef struct Timer *Timer_t;
typedef void (*timer_callback)(Timer_t,void*);



typedef struct TimerMgr *TimerMgr_t;

extern TimerMgr_t CreateTimerMgr();
extern void       DestroyTimerMgr(TimerMgr_t*);
//如果once=1则调用后RunTimerMgr马上返回，否则之后等TerminateTimerMgr调用之后才会返回
extern void       RunTimerMgr(TimerMgr_t,int once);
extern void       TerminateTimerMgr(TimerMgr_t);
extern int32_t        AddTimer(TimerMgr_t,Timer_t);
extern int32_t        RemoveTimer(TimerMgr_t,Timer_t);

extern Timer_t    CreateTimer(struct itimerspec*,timer_callback,void *arg);
extern void       DestroyTimer(Timer_t*);
//默认的itimerspec结构初始器,用于创建固定间隔定时器
extern void       DefaultInit(struct itimerspec*,int32_t interval);


#ifndef TIMERMGR_RUNONCE
#define TIMERMGR_RUNONCE(TIMERMGR) RunTimerMgr(TIMERGER,1)
#endif

#ifndef TIMERMGR_RUN
#define TIMERMGR_RUN(TIMERMGR) RunTimerMgr(TIMERGER,0)
#endif

//创建一个默认的固定间隔定时器,最小单位毫秒
#ifndef DEFAULT_TIMER
#define DEFAULT_TIMER(INTERVAL,CALLBACK,ARG)\
({Timer_t __ret;struct itimerspec __spec;\
  DefaultInit(&__spec,INTERVAL);\
  __ret = CreateTimer(&__spec,CALLBACK,ARG);\
  __ret;})
#endif

#endif
