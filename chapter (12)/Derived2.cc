/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class BaseClass
{
public:
	BaseClass(int ival)
		: ival_(ival)
	{
		std::cout << "BaseClass(int ival) " << std::endl;
	}

	BaseClass()
	{
		std::cout << "BaseClass()" << std::endl;
	}

private:
	int ival_;
};


class DerivedClass : public BaseClass
{
public:
#if 0
	DerivedClass(): //BaseClass()默认会自动调用缺省的构造函数
	{
		std::cout << "DerivedClass()" << std::endl;
	}

	DerivedClass(int i)
	{
		std::cout << "DerivedClass(int)" << std::endl;
	}
#endif
	
};

int main(void)
{
	DerivedClass x1;
	DerivedClass x2;
}
