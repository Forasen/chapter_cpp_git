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

	Complex & operator+=(const Complex &rhs);
	Complex operator+(const Complex &rhs);

	Complex & operator++(); 
	Complex operator++(int);
private:
	double dreal_;
	double dimag_;
};

Complex & Complex::operator+=(const Complex &rhs)
{
	dreal_ += rhs.dreal_;
	dimag_ += rhs.dimag_;

	return *this;
}

Complex Complex::operator+(const Complex &rhs)
{
	return Complex(dreal_ + rhs.dreal_, dimag_ + rhs.dimag_);
}


Complex & Complex::operator++()
{
	++dreal_;
	++dimag_;
	return *this;
}

Complex Complex::operator++(int)
{
	double dreal_tmp = dreal_;
	double dimag_tmp = dimag_;
	++dreal_;
	++dimag_;
	return Complex(dreal_tmp, dimag_tmp);
}


int main(void)
{
	Complex cx1(1.0, 2.0), cx2(3.0, 4.0);
	Complex cxRes;
	cxRes += cx2;
	cx1 += cx2;
	std::cout << "cx1 = ";
	cx1.display();

	cxRes = cx1 + cx2;
	std::cout << "cxRes = ";
	cxRes.display();
	std::cout << std::endl;
	
	int a = 10;
	++a;
	a++;
	std::cout << "++之前的cx2 = ";
	cx2.display();

	Complex cx4 = ++cx2;//
	std::cout << "前置++之后cx4 = ";
	cx4.display();
	std::cout << "cx2 = ";
	cx2.display();

	Complex cx3 = cx2++;
	std::cout << "后置++之后cx3 = ";
	cx3.display();
	std::cout << "cx2 = ";
	cx2.display();

	return 0;
}
