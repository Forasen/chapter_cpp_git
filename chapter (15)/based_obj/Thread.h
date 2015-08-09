/*********************************
 *@fileName: Thread.h
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-07-02 15:14:37
**********************************/

#ifndef __BASED_THREAD_H
#define __BASED_THREAD_H

#include <pthread.h>
#include <functional>

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


#endif

