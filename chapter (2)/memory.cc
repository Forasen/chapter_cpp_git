/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <stdio.h>



int ival = 10;
const int ival2 = 20;
double dval = 30.0;
int main(void)
{
	printf("&ival = %x\n", &ival);
	printf("&ival2 = %x\n", &ival2);
	printf("&dval = %x\n", &dval);

	int ival3 = 40;
	{
	const int ival4 = 50;
	}
	double dval2 = 60.0;
	char *pstr = "123456";

	printf("&ival3 = %x\n", &ival3);
	printf("&ival4 = %x\n", &ival4);
	printf("&dval2 = %x\n", &dval2);
	printf("pstr = %x\n", pstr);


}
