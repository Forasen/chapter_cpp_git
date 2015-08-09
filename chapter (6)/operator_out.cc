/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Complex
{
	friend std::ostream & operator<<(std::ostream &os, const Complex &rhs);
	friend std::istream & operator>>(std::istream &is, Complex &rhs);
public:
	Complex(double dreal = 0.0, double dimag = 0.0)
		: dreal_(dreal),
		  dimag_(dimag)
	{}
	Complex &operator+=(const Complex &rhs);

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

std::ostream & operator<<(std::ostream &os, const Complex &rhs)
{
	os << rhs.dreal_ << " + " << rhs.dimag_ << "i";
	return os;
}


std::istream & operator>>(std::istream &is, Complex &rhs)
{
	is >> rhs.dreal_;
	while(is.get() != '*')
	{}

	is >> rhs.dimag_;
	return is;
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

	std::cout << cxRes << std::endl;


	std::string str = "hello,world!";
	std::cout << str << std::endl;
	std::cout << "请输入一个复数：" << std::endl;
	std::cin >> cxRes;
	std::cout << cxRes << std::endl;

	return 0;
}
