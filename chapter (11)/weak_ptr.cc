/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <memory>

class X
{
public:
	X() {	std::cout << "X()" << std::endl;}
	~X(){	std::cout << "~X()" << std::endl;}

	void fun()
	{	std::cout << "fun()" << std::endl;}
};


int main(void)
{
	std::weak_ptr<X> p;
	{
		std::shared_ptr<X> p2(new X);
		std::cout << "p2's count = " << p2.use_count() << std::endl;

		p = p2;
		std::cout << "after p = p2:" << std::endl;
		std::cout << "p2's count = " << p2.use_count() << std::endl;

		std::shared_ptr<X> p3 = p.lock();
		if(p3)
		{
			p3->fun();
			std::cout << "p3's count = " << p3.use_count() << std::endl;
		}
		else
		{
			std::cout << "obj has been destroyed!" << std::endl;
		}
	}

	std::shared_ptr<X> p4 = p.lock();
	if(p4)
	{
		p4->fun();
		std::cout << "p4's count = " << p4.use_count() << std::endl;
	}
	else
	{
		std::cout << "obj has been destroyed!" << std::endl;
	}

	std::shared_ptr<X> *pthis = new std::shared_ptr<X>(new X);
	delete pthis;
}
