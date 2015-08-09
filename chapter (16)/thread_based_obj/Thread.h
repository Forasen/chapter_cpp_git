/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef __BASED_THREAD_H
#define __BASED_THREAD_H

#include <pthread.h>
#include <functional>

namespace wd
{

class Thread
{
public:
	typedef std::function<void(void)> ThreadCallback;

public:
	Thread(ThreadCallback callback);
	~Thread();

	void start();
	void join();

	static void *runInThread(void *);
	bool isRunning() const;

private:
	pthread_t pthId_;
	bool isRunning_;
	ThreadCallback callback_;
};

}//end of namespace wd
#endif

