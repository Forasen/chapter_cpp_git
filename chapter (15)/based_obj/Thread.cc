/*********************************
 *@fileName: Thread.cc
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-07-02 15:19:16
**********************************/

#include "Thread.h"
#include <iostream>

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
}

bool Thread::isRunning() const
{
	return isRunning_;
}

