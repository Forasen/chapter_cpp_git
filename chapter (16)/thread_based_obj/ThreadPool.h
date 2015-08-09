/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_THREADPOOL_H
#define _WD_THREADPOOL_H

#include "Noncopyable.h"
#include "Buffer.h"
#include <vector>
#include <functional>


namespace wd
{

class Thread;
class ThreadPool : public Noncopyable
{
public:
	typedef std::function<void()> Task;

	ThreadPool(std::size_t numThreads,
			   std::size_t bufSize)
		: numThreads_(numThreads),
		  bufSize_(bufSize),
		  buffer_(bufSize),
		  isExit_(false)
	{}

	~ThreadPool();

	void start();
	void addTask(Task task);
	void runInThread();
private:
	Task getTask();
private:
	std::vector<Thread *> vecThreads_;
	std::size_t numThreads_;
	std::size_t bufSize_;
	Buffer buffer_;
	bool isExit_;
};

}//end of namespace wd

#endif
