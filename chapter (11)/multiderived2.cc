/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class A
{
public:
	A(int xp = 0)
		: ix_(xp)
	{}

	void setx(int ix)
	{	ix_ = ix;}

	void print()
	{	std::cout << "A::ix_" << ix_ << std::endl; }
protected:
	int ix_;
};

class B : virtual public A
{};

class C : virtual public A
{};

class D : public B, public C
{};

int main(void)
{
	D d;
	d.setx(3);
	d.print();

	return 0;
}
