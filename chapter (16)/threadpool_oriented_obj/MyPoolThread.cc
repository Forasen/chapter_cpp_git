/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "MyPoolThread.h"
#include "ThreadPool.h"

namespace wd
{
MyPoolThread::MyPoolThread(ThreadPool & threadpool)
	: threadpool_(threadpool)
{
}

void MyPoolThread::run()
{
	threadpool_.runInThread();
}

}//end of namespace wd
