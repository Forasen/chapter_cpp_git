/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "ConsumerThread.h"
#include "ProducerThread.h"
#include "Buffer.h"


int main(void)
{
	wd::Buffer buffer(10);
	wd::ProducerThread *pProducer = new wd::ProducerThread(buffer);
	wd::ConsumerThread *pConsumer = new wd::ConsumerThread(buffer);
	pProducer->start();
	pConsumer->start();
	pProducer->join();
	pConsumer->join();

	delete pProducer;
	delete pConsumer;
	return 0;
}
