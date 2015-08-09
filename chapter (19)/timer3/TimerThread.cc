/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "TimerThread.h"

TimerThread::TimerThread(int val, int interval, TimerThreadCallback cb)
	: timer_(val, interval, cb),
	  thread_(std::bind(&Timer::start, &timer_))
{}

void TimerThread::start()
{
	thread_.start();
}

void TimerThread::stop()
{
	timer_.stop();
	thread_.join();
}


	  
