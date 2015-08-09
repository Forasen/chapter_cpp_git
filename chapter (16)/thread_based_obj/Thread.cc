/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "Thread.h"
#include <iostream>

namespace wd
{

Thread::Thread(ThreadCallback callback)
	: pthId_(0),
	  isRunning_(false),
	  callback_(callback)
{
	std::cout << "Thread::Thread()" << std::endl;
}

Thread::~Thread()
{
	pthread_detach(pthId_);
	isRunning_ = false;
}

void Thread::start()
{
	pthread_create(&pthId_, NULL, runInThread, this);
	isRunning_ = true;
}

void Thread::join()
{
	pthread_join(pthId_, NULL);
	isRunning_ = false;
}

void * Thread::runInThread(void *arg)
{
	Thread *pThread = static_cast<Thread *>(arg);
	pThread->callback_();
	return NULL;
}

bool Thread::isRunning() const
{
	return isRunning_;
}

}// end of namespace wd

