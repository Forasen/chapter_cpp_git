/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "ProducerThread.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

namespace wd
{

ProducerThread::ProducerThread(Buffer & buffer)
	: buffer_(buffer)
{
}

ProducerThread::~ProducerThread()
{
}

void ProducerThread::run()
{
	processTask();
}

void ProducerThread::processTask()
{
	::srand(time(NULL));
	while(1)
	{
		int num = rand() % 100;
		buffer_.push(num);

		std::cout << "producer a num: " << num << std::endl;
		sleep(1);
	}
}

}//end of namespace wd
