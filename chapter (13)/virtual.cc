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
		return x;
	}
};

class Subclass : public Base
{
public:
	int func(int x)
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
	std::cout << "x = " << x.func(5) << std::endl;
}

int main(void)
{
	Base bc;
	Subclass sc;

	Base &refbase = sc;
	Base *pbase = &sc;
	std::cout << "refbase.func(5) = " << refbase.func(5) << std::endl;
	std::cout << "pbase->func(5) = " << pbase->func(5) << std::endl;

	Sub2 sc2;
	pbase = &sc2;
	std::cout << "pbase->func(5) = " << pbase->func(5) << std::endl;
}
