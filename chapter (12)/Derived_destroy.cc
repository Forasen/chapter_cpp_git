/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class A
{
public:
	A(int ival = 0)
		: ival_(ival)
	{
		std::cout << "A(int ival)" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}

private:
	int ival_;
};


class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}
	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};


class C : public A
{
public:
	C(int xp, int yp) 
		: A(xp),
		  ival2_(yp),
		  b_()
	{
		std::cout << "C(int xp, int yp)" << std::endl;
	}
	~C()
	{
		std::cout << "~C()" << std::endl;
	}

private:
	int ival2_;
	B b_;
};

int main(void)
{
	C c(1, 2);

	return 0;
}
