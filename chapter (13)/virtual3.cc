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
	Base *pBase = NULL;
	Base obj_base;

	obj_base.display();

	pBase = &obj_base;
	pBase->display();


	Child1 *pchild1 = NULL, obj_child1;
	obj_child1.display();
	pchild1 = &obj_child1;
	pchild1->display();

	Child2 *pchild2 = NULL, obj_child2;
	obj_child2.display();
	pchild2 = &obj_child2;
	pchild2->display();
	std::cout << std::endl;

	pBase = &obj_child1;
	pBase->display();
	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);


	std::cout << "sizeof(X) = " << sizeof(X) << std::endl;
	std::cout << "sizeof(Base) = " << sizeof(Base) << std::endl;


	return 0;
}
