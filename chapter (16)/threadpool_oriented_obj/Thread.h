/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_THREAD_H
#define _WD_THREAD_H

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class Thread : public Noncopyable
{
public:
	Thread();
	~Thread();

	void start();
	void join();

	bool isRunning();

	virtual void run() = 0;

	static void* runInThread(void *);

private:
	pthread_t pthId_;
	bool isRunning_;

};

}//end of namespace wd
#endif

