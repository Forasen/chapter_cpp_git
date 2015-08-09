/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>


class Base
{
public:
	Base(const char *pstr)
	{
		std::cout << "Base(const char * pstr)" << std::endl;
		pstr_ = new char [strlen(pstr) + 1];
		strcpy(pstr_, pstr);
	}

	Base(const Base &rhs)
	{
		std::cout << "Base(const Base &rhs)" << std::endl;
		pstr_ = new char[strlen(rhs.pstr_) + 1];
		strcpy(pstr_, rhs.pstr_);
	}

	Base & operator=(const Base &rhs)
	{
		if(this != &rhs)
		{
			delete [] pstr_;
			pstr_ = new char[strlen(rhs.pstr_) + 1];
			strcpy(pstr_, rhs.pstr_);
			std::cout << "Base & operator=(const Base & rhs)" << std::endl;
		}
		return *this;
	}


	~Base()
	{
		std::cout << "~Base()" << std::endl;
		delete [] pstr_;
	}

protected:
	char *pstr_;
};

class Derived : public Base
{
public:
	Derived(const char * pstr) : Base(pstr)
	{
		std::cout << "Derived(const char * pstr)" << std::endl;
	}


	void print()
	{
		std::cout << pstr_ << std::endl;
	}
};

int main(void)
{
	Derived d1("hello!");
	d1.print();
	Derived d2 = d1;
	d2.print();
	std::cout << std::endl;

	d2 = d1;
	d2.print();
}
