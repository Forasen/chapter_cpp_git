/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Complex
{
public:
	Complex(double dreal = 0.0, double dimag = 0.0)
		: dreal_(dreal),
		  dimag_(dimag)
	{}

	void display()
	{
		std::cout << dreal_ << " + " << dimag_ << "i" << std::endl;
	}

public:
	double dreal_;
	double dimag_;
};


Complex operator+(Complex &lhs, Complex &rhs)
{
	return Complex(lhs.dreal_ + rhs.dreal_, 
				   lhs.dimag_ + rhs.dimag_);
}

int main(void)
{
	Complex cx1(1.0, 2.0), cx2(3.0, 4.0);
	Complex cxRes = cx1 + cx2;//
	cxRes.display();

	return 0;
}
