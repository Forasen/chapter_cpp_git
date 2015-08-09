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


	Complex & operator+=(const Complex &rhs);

	void display()
	{
		std::cout << dreal_ << " + " << dimag_ << "i" << std::endl;
	}

private:
	double dreal_;
	double dimag_;
};

inline Complex & Complex::operator+=(const Complex &rhs)
{
	dreal_ += rhs.dreal_;
	dimag_ += rhs.dimag_;
	return *this;
}
Complex operator+(Complex &lhs, Complex &rhs)
{
	Complex cxTmp;
	cxTmp += lhs;
	cxTmp += rhs;
	return cxTmp;
}

int main(void)
{
	Complex cx1(1.0, 2.0), cx2(3.0, 4.0);
	Complex cxRes = cx1 + cx2;//
	cxRes.display();

	return 0;
}
