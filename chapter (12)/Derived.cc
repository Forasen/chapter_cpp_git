/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class BaseClass
{
private:
	int ival_;
};


class DerivedClass : public BaseClass
{
public:
	DerivedClass()
	{
		std::cout << "DerivedClass()" << std::endl;
	}

	DerivedClass(int i)
	{
		std::cout << "DerivedClass(int)" << std::endl;
	}
	
};

int main(void)
{
	DerivedClass x1(5);
	DerivedClass x2;
}
