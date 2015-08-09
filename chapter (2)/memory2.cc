/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <stdio.h>

int test0(void)
{
	int ival = 10;
	double dval =20;
	char ch1 = 'A';
	char ch2 = 'B';
	double dval2 = 30.0;

	printf("&ival = %x\n", &ival);
	printf("&dval = %x\n", &dval);
	printf("&ch1 = %x\n", &ch1);
	printf("&ch2 = %x\n", &ch2);
	printf("&dval2 = %x\n", &dval2);

	return 0;
}

void fun1(int a)
{
	printf("&a = %x\n", &a);
}

void fun2(int a)
{	
	printf("&a = %x\n", &a);
	fun1(a);
}

int main(void)
{
	int a = 1;
	fun2(a);
}
