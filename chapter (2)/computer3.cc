/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <stdio.h>
#include <iostream>
#include <string.h>

class Computer
{
public:
	Computer(const char *str, float p)
		: fPrice_(p)
	{
		std::cout << "创建对象" << std::endl;
		pBrand_ = new char[strlen(str) + 1];
		strcpy(pBrand_, str);
	}

	Computer(const Computer &rhs)
		: fPrice_(rhs.fPrice_)
	{
		pBrand_ = new char[strlen(rhs.pBrand_) + 1];
		strcpy(pBrand_, rhs.pBrand_);
	}

	~Computer()
	{
		printf("pBrand_ = %x\n", pBrand_);
		delete []pBrand_;
		std::cout << "清理现场" << std::endl;
	}


	void print()
	{
		std::cout << "品牌：" << pBrand_ << std::endl;
		std::cout << "价格：" << fPrice_ << std::endl;
	}
private:
	char * pBrand_;
	float fPrice_;
};

int main(void)
{
	Computer pc1("Dell", 7000);
	pc1.print();

	std::cout << std::endl;
	Computer pc2 = pc1;
	pc2.print();

	return 0;
}
