/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Base
{
public:
	virtual void display()
	{
		std::cout << "Base::display()" << std::endl;
	}

	void call_base_1()
	{
		display();
	}

	void call_base_2()
	{
		Base::display();
	}
};


class Child : public Base
{
public:
	void display()
	{
		std::cout << "Child::display()" << std::endl;
	}

	void call_child_1()
	{
		display();
	}
};


void display(Base * pb)
{
	pb->display();
}

int main(void)
{
	Base obj_base;
	Child obj_child;

	obj_base.call_base_1();
	obj_child.call_child_1();


	std::cout << std::endl;
	Base *pbase = &obj_base;
	pbase->call_base_1();
	pbase->call_base_2();

	std::cout << std::endl;
	pbase = &obj_child;
	pbase->call_base_1();
	pbase->call_base_2();

    return 0;
}
