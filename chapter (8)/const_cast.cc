/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <stdio.h>
#include <iostream>

int  func(int & a)
{
	++a;
	int *pa = &a;
	printf("pa = %x\n", pa);
	return a;
}

int main(void)
{
	const int ival = 10ȥ;

	int ret = func(const_cast<int &>(ival));
	std::cout << "ret = " << ret << std::endl;
	std::cout << "ival = " << ival << std::endl;
	printf("&ival = %x\n", &ival);
	return 0;
}
