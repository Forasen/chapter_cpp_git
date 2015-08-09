/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Base
{
public:
	virtual int func(int x)
	{
		std::cout << "This is Base class " << std::endl;
		return 5;
	}
};

class Subclass : public Base
{
public:
	virtual int func(float x)
	{
		std::cout << "This is Sub Class" << std::endl;

		return 2 * x;
	}
};

class Sub2 : public Base
{
public:
	int func(int x)
	{
		std::cout << "This is Sub2 Class " << std::endl;
		return x * x;
	}
};

void test(Base &x)
{
	//std::cout << "x = " << x.func(5) << std::endl;
}

int main(void)
{
	Base bc;
	Subclass sc;

	Base &refbase = sc;
	Base *pbase = &sc;
	std::cout << "sc.func(5) = " << sc.func(5) << std::endl;

	std::cout << std::endl;
	Sub2 sc2;
	pbase = &sc2;
}
