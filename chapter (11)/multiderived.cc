/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class A
{
public:
	void print()
	{
		std::cout << "A()" << std::endl;
	}
};

class B
{
public:
	void print()
	{
		std::cout << "B()" << std::endl;
	}
};


class C : public A, public B
{
public:
	void display()
	{
		//show();
		A::print();
	}

	void print()
	{
		std::cout << "C()" << std::endl;
	}
};


int main(void)
{
	C c;
	c.print();
	c.display();


	return 0;
}
