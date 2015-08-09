/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_CONSUMERTHREAD_H
#define _WD_CONSUMERTHREAD_H

#include "Thread.h"

namespace wd
{

class Buffer;

class ConsumerThread : public Thread
{
public: 
	ConsumerThread(Buffer & buffer);
	virtual ~ConsumerThread();

	void run();

private:
	void processTask();

private:
	Buffer & buffer_;
};

}//end of namespace wd

#endif
