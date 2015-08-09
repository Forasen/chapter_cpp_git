/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_PRODUCERTHREAD_H
#define _WD_PRODUCERTHREAD_H
#include "Thread.h"

namespace wd
{

class Buffer;

class ProducerThread : public Thread
{
public:
	ProducerThread(Buffer & buffer);
	virtual ~ProducerThread();

	void run();
private:
	void processTask();
private:
	Buffer & buffer_;
};


}//end of namespace wd

#endif
