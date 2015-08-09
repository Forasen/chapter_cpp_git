/*********************************
 *@fileName: const.cc
 *@author  : lemon
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

#define Max 100

int main(void)
{
	const int a = 10;

	const int b = 20;

	int c = 30;
	const int *pa = &c;

	int const *pb = &c;

	int * const pd = &c;
						
	*pd = 40;
	std::cout << "c = " << c << std::endl;

	int d = 50;
	pd = &d;

	return 0;
}
