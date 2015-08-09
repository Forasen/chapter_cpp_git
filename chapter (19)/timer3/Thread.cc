/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include "Thread.h"

Thread::Thread(Callback cb)
	: pthid_(0),
	  isStarted_(false),
	  cb_(cb)
{}

Thread::~Thread()
{
	if(isStarted_)
	{
		pthread_detach(pthid_);
		isStarted_ = false;
	}
}

void Thread::start()
{
	pthread_create(&pthid_, NULL, &Thread::runInThread, this);
	isStarted_ = true;
}

void Thread::join()
{
	pthread_join(pthid_, NULL);
	isStarted_ = false;
}

void* Thread::runInThread(void *arg)
{
	Thread *pThread = static_cast<Thread *>(arg);
	pThread->cb_();

	return NULL;
}
