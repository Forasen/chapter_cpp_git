/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class X
{
public:
	X() : ix_(3){}
	int ix_;
};

int main(void)
{
	int a = 10;
	int *pa = &a;

	int	X::*pix = &X::ix_;

	X x;
	std::cout << x.*pix << std::endl;

	int b = 20;
	int c = a + b;
}
