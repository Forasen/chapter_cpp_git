/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "ConsumerThread.h"
#include "Buffer.h"
#include <unistd.h>
#include <iostream>

namespace wd
{

ConsumerThread::ConsumerThread(Buffer & buffer)
	: buffer_(buffer)
{}

ConsumerThread::~ConsumerThread()
{}

void ConsumerThread::run()
{
	processTask();
}

void ConsumerThread::processTask()
{
	while(1)
	{
		int num = buffer_.pop();
		std::cout << "consumer a num: " << num << std::endl;
		sleep(2);
	}
}

}//end of namespace wd
