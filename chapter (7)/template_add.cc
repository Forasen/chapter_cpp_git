/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string>

template <typename T>
T add(const T & a, const T & b)
{
	return a + b;
}

int main(void)
{
	std::cout << add(10, 20) << std::endl;//参数的隐式实例化
	std::cout << add(1.0, 2.0) << std::endl;

	std::string x("Hello"), y(",world");
	std::cout << add(x, y) << std::endl;

	const char *pa = "hello";
	const char *pb = "world";
	add(pa,pb);


	return 0;
}



