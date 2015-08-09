/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
template<typename T>

T Max(T x, T y);

template<typename T>
T Max(T x, T y, T z)
{
	std::cout << "template func Max(T,T,T)" << std::endl;
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}


int Max(int a, int b)
{
	std::cout << "普通函数Max" << std::endl;
	return a > b ? a : b;
}

int main(void)
{
	int ival1 = 4, ival2 = 5;
	std::cout << Max(4, 5) << std::endl;
	
	double dval1 = 3.33, dval2 = 4.44;
	std::cout << Max(dval1, dval2) << std::endl;

	std::cout << Max<char>('A', 'a') << std::endl;//参数显式实例化

	double dval3 = 5.55;
	std::cout << Max<double>(dval1, dval2, dval3) << std::endl;

	return 0;
}

template<typename T>
T Max(T x, T y)
{
	std::cout << "模板函数Max" << std::endl;
	return x > y ? x : y;
}
