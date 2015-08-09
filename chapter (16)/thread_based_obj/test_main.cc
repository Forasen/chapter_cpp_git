/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "ThreadPool.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


void task1()
{
	::srand(time(NULL));
	int num = rand() % 100;
	std::cout << "print a number: " << num << std::endl;
}

int main(void)
{
	wd::ThreadPool threadpool(4, 10);
	threadpool.start();

	while(1)
	{
		threadpool.addTask(task1);
		std::cout << "添加任务" << std::endl;
		sleep(1);
	}

	return 0;
}
