/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

double add2(double a, double b)
{
	return a + b;
}

int main(void)
{
	int ival1 = 3;
	int ival2 = 4;
	printf("ival1 + ival2 = %d\n", add(ival1, ival2));
	return 0;
}


