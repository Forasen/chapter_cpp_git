/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

void swap(int * pa, int * pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void swap(int & refa, int & refb)
{
	int tmp = refa;
	refa = refb;
	refb = tmp;
}

void swap2(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int arr[5] = {1, 2, 3, 4, 5};

int & index(int idx)
{
	return arr[idx];
}


int & func()
{
	int a = 10;
	return a;
}

int & func2()
{
	int *pa = new int(3);
	return *pa;
}

int main(void)
{
	int a = 10; 
	int b = 20;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	index(2) = 100;
	std::cout << "call index(2): " << index(2) << std::endl;

	std::cout << "func()=" << func() << std::endl;
	{
		int a = 20;
		int b = 30;
		int c = a + func2() + b;
	}
	while(1){}

	return 0;
	
}

int test0(void)
{
	int a = 10;
	int &refa = a;
	std::cout << "修改之前：a = " << a << std::endl;

	refa = 20;
	std::cout << "修改之后：a = " << a << std::endl;


	int b = 40;

	refa = b;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;


	std::cout << "a's address:" << &a << std::endl;
	std::cout << "a's address:" << &refa << std::endl;

	const int &refb = 30;
	std::cout << "refb = " << refb << std::endl;

}


