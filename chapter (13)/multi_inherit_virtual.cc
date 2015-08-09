/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class A
{
public:
	virtual void a()
	{	std::cout << "A::a()" << std::endl;}

	virtual void b()
	{	std::cout << "A::b()" << std::endl;}

	virtual void c()
	{	std::cout << "A::c()" << std::endl;}
};

class B
{
public:
	virtual void a()
	{	std::cout << "B::a()" << std::endl;}

	virtual void b()
	{	std::cout << "B::b()" << std::endl;}

	void c()
	{	std::cout << "B::c()" << std::endl;}

	void d()
	{	std::cout << "B::d()" << std::endl;}
};

class C : public A, public B
{
public:
	virtual void a()
	{	std::cout << "C::a()" << std::endl;	}

	void c()
	{	std::cout << "C::c()" << std::endl;	}

	void d()
	{	std::cout << "C::d()" << std::endl;	}
};


int main(void)
{
	C c;

	std::cout << std::endl;

	A *pa = &c;
	pa->a();
	pa->b();
	pa->c();

	std::cout << std::endl;
	B *pb = &c;
	pb->a();
	pb->b();
	pb->c();
	pb->d();
	std::cout << std::endl;

	C *pc = &c;
	pc->a();
	pc->c();
	pc->d();
}
