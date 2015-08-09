/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Computer
{
public:
	Computer(float price)
		: fPrice_(price)
	{
		total_price_ += fPrice_;
	}

	~Computer()
	{
		total_price_ -= fPrice_;
	}

	void print()
	{
		std::cout << "总价：" << total_price_ << std::endl;
	}

private:
	float fPrice_;
	static float total_price_;
};

float Computer::total_price_ = 0.0;

int main(void)
{
	Computer pc1(7000);
	std::cout << "购买电脑1之后" << std::endl;
	pc1.print();
	Computer pc2(4999);
	std::cout << "购买电脑2之后" << std::endl;
	pc2.print();
	Computer pc3(2500);
	std::cout << "购买电脑3之后" << std::endl;
	pc1.print();

	pc2.~Computer();
	std::cout << "退还电脑2之后" << std::endl;
	pc3.print();

	std::cout << "sizeof(Computer) = " << sizeof(Computer)
			  << std::endl;

	return 0;
}

