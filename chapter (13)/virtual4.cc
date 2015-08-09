/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class X
{};

class Base
{
public:
	virtual void display()
	{
		std::cout << "Base::display()" << std::endl;
	}

	virtual void show()
	{
		std::cout << "Base::show()" << std::endl;
	}

	Base getBase()
	{
		std::cout << "Base::getBase()" << std::endl;
		return *this;
	}
};


class Child1 : public Base
{
public:
#if 1
	void display()
	{
		std::cout << "Child1::display()" << std::endl;
	}
#endif

	Child1 getChild()
	{
		std::cout << "Child1::getChild()" << std::endl;
		return *this;
	}
};

class Child2 : public Base
{
public:
	void display()
	{
		std::cout << "Child2::display()" << std::endl;
	}

};

void display(Base * pb)
{
	pb->display();
}

int main(void)
{
	Child1 obj_child1;

	obj_child1.display();

	obj_child1.Base::display();

	Base *pbase = &obj_child1;
	pbase->getBase();

	return 0;
}
