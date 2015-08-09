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

};


class Child : public Base
{
public:
	void display()
	{
		std::cout << "Child::display()" << std::endl;
	}
};


void display(Base * pb)
{
	pb->display();
}

int main(void)
{
	Base obj_base;
	Base &refBase1 =  obj_base;
	refBase1.display();


	Child obj_child;
	Base &refBase2 = obj_child;
	refBase2.display();

	std::cout << std::endl;

	refBase1 = obj_child;
	refBase1.display();

	std::cout << std::endl;
	refBase2 = obj_base;
	refBase2.display();

}
