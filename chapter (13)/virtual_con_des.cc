/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Base0
{
public:
	Base0(){}

	virtual void func1()
	{
		std::cout << "Base0::func1()" << std::endl;
	}

	virtual void func2()
	{
		std::cout << "Base0:func2()" << std::endl;
	}

	~Base0()
	{}
};


class Base1 : public Base0
{
public:
	Base1()
	{
		this->func1();
	}

	virtual void func1()
	{
		std::cout << "Base1::func1()" << std::endl;
	}

	virtual void func2()
	{
		std::cout << "Base1::func2()" << std::endl;
	}

	~Base1()
	{
		std::cout << "~Base1()   ";
		func2();
	}
};

class Subclass : public Base1
{
public:

	Subclass()
	{
		func1();
	}
	virtual void func1()
	{
		std::cout << "Subclass::func1()" << std::endl;
	}

	virtual void func2()
	{
		std::cout << "Subclass::func2()" << std::endl;
	}

	~Subclass()
	{}
};

int main(void)
{
	Subclass sc;

	return 0;
}
