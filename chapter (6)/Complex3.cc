/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Complex
{
	friend Complex operator+(const Complex &lhs, const Complex &rhs);
public:
	Complex(double dreal = 0.0, double dimag = 0.0)
		: dreal_(dreal),
		  dimag_(dimag)
	{}

	void display()
	{
		std::cout << dreal_ << " + " << dimag_ << "i" << std::endl;
	}

private:
	double dreal_;
	double dimag_;
};

Complex operator+(const Complex &lhs, const Complex &rhs)
{
	return Complex(lhs.dreal_ + rhs.dreal_, 
				   lhs.dimag_ + rhs.dimag_);
}

int main(void)
{
	Complex cx1(1.0, 2.0), cx2(3.0, 4.0);
	Complex cxRes = cx1 + cx2;//
	cxRes.display();
#if 1
	int a = 1, b =2 ;
	int c = a + b;
#endif

	return 0;
}
