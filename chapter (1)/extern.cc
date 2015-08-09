/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif
int add(int a, int b)
{
	return a + b;
}
#ifdef __cplusplus
}
#endif

double add(double a, double b)
{
	return a + b;
}

double add(int a, double b, int c)
{
	return a + b + c;
}

int main(void)
{
	int ival1 = 3;
	int ival2 = 4;
	std::cout << "ival1 + ival2 = " << add(ival1, ival2) <<std::endl;
}
