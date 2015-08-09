/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class A
{
public:
	A(int x = 0) : x_(x)
	{
		std::cout << "A::A(int x)" << std::endl;
	}

	~A()
	{
		std::cout << "A::~A()" << std::endl;
	}

	void print()
	{
		std::cout << "A::x_ = " << x_ << std::endl;
	}

private:
	int x_;
};


class B : virtual public A
{
public:
	B(int xp) : A(xp)
	{
		std::cout << "B::B(int xp)" << std::endl;
	}

	~B()
	{
		std::cout << "B::~B()" << std::endl;
	}

};

class C : virtual public A
{
public:
	C(int xp) : A(xp)
	{
		std::cout << "C::C(int xp)" << std::endl;
	}

	~C()
	{
		std::cout << "C::~C()" << std::endl;
	}
};


class D : public B, public C
{
public:
	D(int xp) : B(xp), C(xp), A(xp)
	{
		std::cout << "D::D(int xp)" << std::endl;
	}

	~D()
	{
		std::cout << "D::~D()" << std::endl;
	}
};


int main(void)
{
	D d(2);
	d.print();
	std::cout << std::endl;


	getchar();

	return 0;
}
