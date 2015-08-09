/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _TIMERTHREAD_H
#define _TIMERTHREAD_H

#include "Thread.h"
#include "Timer.h"
#include <functional>

class TimerThread : private Noncopyable
{
public:
	typedef std::function<void()> TimerThreadCallback;

	TimerThread(int val, int interval, TimerThreadCallback cb); 

	void start();
	void stop();

private:
	Timer timer_;
	Thread thread_;
};


#endif
