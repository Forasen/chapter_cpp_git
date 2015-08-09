/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "TimerThread.h"
#include <stdio.h>
#include <unistd.h>

void foo()
{
	printf("foo() timer call\n");
}


int main(void)
{
	TimerThread timerThread(4, 5, &foo);
	timerThread.start();
#if 1
	while(1)
	{
		printf("hello,world\n");
		sleep(1);
	}
	timerThread.stop();
#endif

	return 0;
}
