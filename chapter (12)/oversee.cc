/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Base
{
public:
	int func(int i)
	{
		ival_ = i;
		return ival_;
	}


protected:
	int ival_;
};

class Derived : public Base
{
public:
	int func()
	{
		ival_ = 9;
		Base::ival_ = 22;
		return ival_;
	}

private:
	int ival_;
};

int main(void)
{
	Derived d1;
	std::cout << d1.func() << std::endl;
	std::cout << d1.Base::func(1) << std::endl;

	return 0;
}
