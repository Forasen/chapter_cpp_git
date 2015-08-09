/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <functional>


int func(int x, int y)
{
	std::cout << "func(int,int)" << std::endl;
	return x + y;
}

class A
{
public:
	int func(int x, int y)
	{
		std::cout << "A::func(int x, int y)" << std::endl;
		return x + y;
	}
};

int test(void)
{
	auto f1 = std::bind(func, 10, 20);
	std::cout << "10 + 20 = " << f1() << std::endl;

	auto f2 = std::bind(func, std::placeholders::_1,
			10);
	std::cout << f2(30, 2, 11, 22, 1, 2,3,4,5,6,7) << std::endl;

	A a;
	auto f3 = std::bind(&A::func, a, std::placeholders::_1, 11);
	std::cout << "f3() = " << f3(22, 1 ,2,3,45,5) << std::endl;

	return 0;
}


void f(int n1, int n2, int n3, const int &n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' '
			  << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
	return n1;
}

struct Foo
{
	void print_sum(int n1, int n2)
	{
		std::cout << n1 + n2 << std::endl;
	}
	
	int data = 11;
};


int main(void)
{
	using namespace std::placeholders;

	int n = 7;
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001);

	Foo foo;
	auto f2 = std::bind(&Foo::print_sum, &foo, 95, _1);
	f2(5);

	auto f4 = std::bind(&Foo::data, _1);
	std::cout << f4(foo) << std::endl;
}
