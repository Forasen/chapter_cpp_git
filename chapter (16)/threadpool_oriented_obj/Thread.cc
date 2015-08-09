/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "Thread.h"
#include <iostream>

namespace wd
{

Thread::Thread()
	: pthId_(0),
	  isRunning_(false)
{
	std::cout << "Thread::Thread()" << std::endl;
}

Thread::~Thread()
{
	pthread_detach(pthId_);
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

void* Thread::runInThread(void *arg)//static, 不带this指针
{
	Thread *pThread = static_cast<Thread *>(arg);
	pThread->run();
	return NULL;
}


}//end of namespace wd
