/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>


class Base
{
public:
	Base()
	{
		std::cout << "Base()" << std::endl;
		pstr_ = new char[1];
	}
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
	Derived()
	{
		pstr2_ = new char[1];
		std::cout << "Derived()" << std::endl;
	}
	Derived(const char * pstr1, const char * pstr2) 
		: Base(pstr1)
	{
		pstr2_ = new char[strlen(pstr2) + 1];
		strcpy(pstr2_, pstr2);
		std::cout << "Derived(const char*, const char*)" << std::endl;
	}

	Derived(const Derived & rhs)
		: Base(rhs)//(const Base &rhs) = rhs
	{
		std::cout << "Derived(const Derived &rhs)" << std::endl;
		pstr2_ = new char[strlen(rhs.pstr2_) + 1];
		strcpy(pstr2_, rhs.pstr2_);
	}

	Derived & operator=(const Derived &rhs)
	{
		if(this != &rhs)
		{
			Base::operator=(rhs);
			delete[] pstr2_;
			pstr2_ = new char [strlen(rhs.pstr2_) + 1];
			strcpy(pstr2_, rhs.pstr2_);
			std::cout << "Derived & operator=(const Derived &)" << std::endl;
		}
		return *this;
	}


	~Derived()
	{
		std::cout << "~Derived()" << std::endl;
		delete []pstr2_;
	}
	void print()
	{
		std::cout << pstr_ <<  ":" 
				  << pstr2_ << std::endl;
	}

private:
	char * pstr2_;
};

int main(void)
{
	Derived d1("hello,", "world!");
	d1.print();
	Derived d2 = d1;
	d2.print();
	std::cout << std::endl;

	Derived d3;
	d3 = d1;
	d3.print();
}
