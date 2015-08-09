/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class A
{
public:
	virtual void display() = 0;
};


class B : public A
{
public:
	virtual void display()
	{
		std::cout << "B::display()" << std::endl;
	}
};

class C : public B
{
public:
	virtual void display()
	{
		std::cout << "C::display()" << std::endl;
	}
};


void display(A *a)
{
	a->display();
}


int main(void)
{
	A *pa = new B;
	display(pa);
	pa = new C;
	display(pa);

	return 0;
}
