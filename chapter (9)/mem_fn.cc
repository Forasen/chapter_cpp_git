/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <functional>

struct Foo
{
	void display_greeting()
	{
		std::cout << "Hello,world!" << std::endl;
	}

	void display_num(int i)
	{	
		std::cout << "number:" << i << std::endl;
	}

	int data = 7;
};

int main(void)
{
	Foo foo;
	auto f1 = std::mem_fn(&Foo::display_greeting);
	f1(&foo);

	auto f2 = std::mem_fn(&Foo::display_num);
	f2(&foo, 42);

	auto access_data = std::mem_fn(&Foo::data);
	std::cout << access_data(&foo) << std::endl;
}
