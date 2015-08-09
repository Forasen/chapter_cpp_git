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
		std::cout << "This is Base class" << std::endl;
		return x;
	}
};

class Subclass : public Base
{
public:
	virtual int func(float x)
	{
		std::cout << "This is Sub class " << std::endl;
		int y = static_cast<int>(x);
		return y;
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
	test(bc);
	test(sc);
	std::cout << std::endl;

	sc.func(5);

	Base &refbase = sc;
	std::cout << refbase.func(6.6) << std::endl;
	
	Base *pbase = &sc;
	std::cout << pbase->func(7.7) << std::endl;

	std::cout << "sizeof(Subclass) = " << sizeof(Subclass) << std::endl;

	return 0;
}
