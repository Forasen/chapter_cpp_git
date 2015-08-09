/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _TIMER_H
#define _TIMER_H

#include "Noncopyable.h"
#include <functional>

class Timer : private Noncopyable
{
public:
	typedef std::function<void()> TimerCallback;

	Timer(int val,
		  int interval,
		  TimerCallback cb);
	~Timer();

	void start();
	void stop();

private:
	int timerfd_;
	int val_;
	int interval_;
	TimerCallback cb_;
	bool isStarted_;
};

#endif
