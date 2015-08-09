/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "MyTask.h"
#include "ThreadPool.h"
#include <unistd.h>
#include <iostream>

int main(void)
{
	wd::Task *pTask = new wd::MyTask;
	wd::ThreadPool threadpool(4, 10);
	threadpool.start();

	while(1)
	{
		threadpool.addTask(pTask);
		sleep(1);
	}

	delete pTask;
	return 0;
}
