/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

template <typename T, int NUM>
T func(T a)
{
	return a * NUM;
}

int main(void)
{
	int add(int a, int b);
	std::cout << func<int,5>(3) << std::endl;
}
