/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "Thread.h"
#include "ThreadPool.h"

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
			delete (*it);
		}
	}
	vecThreads_.clear();
}


void ThreadPool::start()
{
	for(std::size_t idx = 0; idx != numThreads_; ++idx)
	{
		Thread *pThread = new Thread(
				std::bind(&ThreadPool::runInThread, this));
		vecThreads_.push_back(pThread);
		pThread->start();
	}
}


void ThreadPool::addTask(Task task)
{
	buffer_.push(task);
}

Task ThreadPool::getTask()
{
	return buffer_.pop();
}

void ThreadPool::runInThread()
{
	while(!isExit_)
	{
		Task task = getTask();	
		if(task != NULL)
			task();//执行任务
	}
}

}//end of namespace wd
