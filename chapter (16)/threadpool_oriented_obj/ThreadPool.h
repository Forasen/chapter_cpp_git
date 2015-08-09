/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_THREADPOOL_H
#define _WD_THREADPOOL_H

#include "Noncopyable.h"
#include "Buffer.h"
#include <vector>


namespace wd
{

class Thread;
class Task;
class ThreadPool : public Noncopyable
{
public:
	ThreadPool(std::size_t numThreads,
			   std::size_t bufSize)
		: numThreads_(numThreads),
		  bufSize_(bufSize),
		  buffer_(bufSize),
		  isExit_(false)
	{}

	~ThreadPool();

	void start();
	void addTask(Task *ptask);
	void runInThread();
private:
	Task * getTask();
private:
	std::vector<Thread *> vecThreads_;
	std::size_t numThreads_;
	std::size_t bufSize_;
	Buffer buffer_;//这里需要是Buffer的实现,所以要引入的是头文件
	bool isExit_;
};

}//end of namespace wd

#endif
