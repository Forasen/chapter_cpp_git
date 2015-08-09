/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "Timer.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/timerfd.h>
#include <string.h>
#include <poll.h>

int createTimerfd()
{
	int timerfd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(-1 == timerfd)
	{
		perror("timerfd_create error");
	}
	return timerfd;
}

void setTimerfd(int timerfd, int value, int interval)
{
	struct itimerspec val;
	memset(&val, 0, sizeof(val));
	val.it_value.tv_sec = value;
	val.it_interval.tv_sec = interval;

	if(-1 == ::timerfd_settime(timerfd, 0, &val, NULL))
	{
		perror("timerfd_settime error");
	}
}

void stopTimerfd(int timerfd)
{
	setTimerfd(timerfd, 0, 0);
}

uint64_t readTimerfd(int timerfd)
{
	uint64_t howmany;
	if(-1 == ::read(timerfd, &howmany, sizeof(howmany)))
	{
		perror("read timerfd error");
	}
	return howmany;//表示超时次数
}

Timer::Timer(int val, int interval, TimerCallback cb)
	: timerfd_(createTimerfd()),
	  val_(val),
	  interval_(interval),
	  cb_(cb),
	  isStarted_(false)
{
}

Timer::~Timer()
{
	if(isStarted_)
	{
		stop();
		::close(timerfd_);
	}
}

void Timer::start()
{
	setTimerfd(timerfd_, val_, interval_);
	isStarted_ = true;

	struct pollfd pfd;
	pfd.fd = timerfd_;
	pfd.events = POLLIN;

	int ret;
	while(isStarted_)
	{
		ret = ::poll(&pfd, 1, 5000);
		if(-1 == ret)
		{
			if(errno == EINTR)
				continue;
			perror("poll");
			exit(EXIT_FAILURE);
		}
		else if(0 == ret)
		{
			printf("timeout\n");
			continue;
		}
		if(pfd.revents == POLLIN)
		{
			uint64_t tmp = readTimerfd(timerfd_);
			printf("readTimerfd = %llu\n", tmp);
			cb_();
		}
	}
}

void Timer::stop()
{
	isStarted_ = false;
	stopTimerfd(timerfd_);
}
