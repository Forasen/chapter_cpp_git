/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "computer2.h"
#include <string.h>
#include <iostream>

#if 1
Computer::Computer()
{
	std::cout << "Computer::Computer()" << std::endl;
	strcpy(pBrand_, "Lenovo");
	fPrice_ = 4999;
}
#endif

Computer::Computer(char *pBrand, float fPrice)
{
	std::cout << "Computer::Computer(char*, float)" << std::endl;
	strcpy(pBrand_, pBrand);
	fPrice_ = fPrice;
}

void Computer::print()
{
	std::cout << "品牌：" << this->pBrand_ << std::endl;
	std::cout << "价格：" << this->fPrice_ << std::endl;
}

void Computer::setBrand(char *sz)
{
	strcpy(pBrand_, sz);
}

void Computer::setPrice(float price)
{
	fPrice_ = price;
}

int main(void)
{
	Computer pc1;
#if 1
	pc1.setBrand("Mac");
	pc1.setPrice(9999);
#endif
	pc1.print();

	std::cout << "sizeof(Computer) = " 
			  << sizeof(Computer) << std::endl;
	{
		Computer pc2;
		pc2.setPrice(5000);
		pc2.setBrand("lenovo");
	}

	Computer pc3;
	pc3.print();

	std::cout << std::endl;
	Computer pc4("Dell", 7999);
	pc4.print();
	return 0;
}
