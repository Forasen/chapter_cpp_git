/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#ifndef __THREAD_H
#define __THREAD_H

#include <pthread.h>
#include <functional>

#include "Noncopyable.h"

class Thread : private Noncopyable
{
public:
	typedef std::function<void()> Callback;
	
	explicit Thread(Callback cb);
	~Thread();

	void start();
	void join();

	static void *runInThread(void *arg);

private:
	pthread_t pthid_;
	bool isStarted_;
	Callback cb_;
};
#endif
