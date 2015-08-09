/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Demo
{

public:
	double operator()(double x, double y)
	{
		return x > y ? x : y;
	}

	double operator()(double x, double y, double z)
	{
		return (x + y) * z;
	}
};


int main(void)
{
	Demo d1;
	std::cout << "2.5 与0.2比较,较大的是：" << d1(2.5, 0.2) << std::endl;
	std::cout << "(1.2 + 1.5) * 7.0 = " << d1(1.2, 1.5, 7.0) << std::endl;
	return 0;
}
