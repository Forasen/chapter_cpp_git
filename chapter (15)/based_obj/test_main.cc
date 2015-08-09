/*********************************
 *@fileName: test_main.cc
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-07-02 15:35:53
**********************************/

#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

void print_num()
{
	::srand(time(NULL));
	while(1)
	{
		int inum =  rand() % 100;
		std::cout << "print a num : " << inum << std::endl;
	
		sleep(1);
	}
}


struct Foo
{
	Foo(int num) : num_(num){}

	void print_num(int i)
	{
		std::cout << "print num_ + i = " << num_ + i << std::endl;
	}

	int num_;
};


int main(void)
{
	//Thread thread(print_num);//回调函数注册
	Foo foo(10);
	Thread thread(std::bind(&Foo::print_num, foo, 20));
	thread.start();
	thread.join();

	return 0;
}
