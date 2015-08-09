/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

int add(int a, int b = 10)
{
	return a + b;
}
int add(int a, int b, int c, int d = 11)
{
	return a + b + c + d;
}

int main(void)
{
	int ival1 = 3;
	int ival2 = 4;
	int ival3 = 5;
	int ival4 = 6;

	std::cout << add(ival1) << std::endl;
	std::cout << add(ival1, ival2) << std::endl;
	std::cout << add(ival1, ival2, ival3, ival4) << std::endl;

    return 0;
}
