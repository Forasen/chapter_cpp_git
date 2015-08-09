/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_MYTASK_H
#define _WD_MYTASK_H

#include "Task.h" 
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace wd
{
class MyTask : public Task
{
public:
	
	void process()
	{
		::srand(time(NULL));
		while(1)
		{
			int num = rand() % 100;
			std::cout << "print a num : " << num << std::endl;
			sleep(1);
		}
	}
};

}//end of namespace wd

#endif
