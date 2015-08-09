/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_MYPOOLTHREAD_
#define _WD_MYPOOLTHREAD_

#include "Thread.h"

namespace wd
{

class ThreadPool;

class MyPoolThread : public Thread
{
public:
	MyPoolThread(ThreadPool & threadpool);

	void run();

private:
	ThreadPool & threadpool_;
};

}//end of namespace wd

#endif
