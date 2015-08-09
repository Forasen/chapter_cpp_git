/*********************************
 *@fileName: test_thread.cc
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-07-02 10:05:47
**********************************/

#include "Thread.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <memory>

namespace wd
{

class MyThread : public Thread
{
public:

	virtual void run()
	{
		::srand(time(NULL));
		while(1)
		{
			int inum = rand() % 100;
			std::cout << "print a number: " << inum << std::endl;
			sleep(1);
		}
	}
};

}// end of namespace wd


int main(void)
{
	wd::MyThread *pThread = new wd::MyThread;
	std::unique_ptr<wd::MyThread> pThreadPtr(pThread);
	pThreadPtr->start();
	pThreadPtr->join();

	return 0;
}
