/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "ThreadPool.h"
#include "MyPoolThread.h"
#include "Task.h"

namespace wd
{

ThreadPool::~ThreadPool()
{
	if(isExit_ == false)
	{
		isExit_ = true;
		std::vector<Thread *>::iterator it;
		for(it = vecThreads_.begin(); it != vecThreads_.end(); ++it)
		{
			(*it)->join();
			delete *it;
		}
	}
	vecThreads_.clear();
}


void ThreadPool::start()
{
	for(std::size_t idx = 0; idx != numThreads_; ++idx)
	{
		Thread *pThread = new MyPoolThread(*this);
		vecThreads_.push_back(pThread);
		pThread->start();
	}
}


void ThreadPool::addTask(Task *ptask)
{
	buffer_.push(ptask);
}

Task * ThreadPool::getTask()
{
	return buffer_.pop();
}

void ThreadPool::runInThread()
{
	while(!isExit_)
	{
		Task *ptask = getTask();	
		if(ptask != NULL)
			ptask->process();//Ö´ÐÐÈÎÎñ
	}
}

}//end of namespace wd
