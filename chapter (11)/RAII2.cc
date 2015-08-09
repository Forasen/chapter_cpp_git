/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

template<typename T>
class RAII
{
public:
	RAII():ptr_(NULL)
	{}

	RAII(T *ptr)
		: ptr_(ptr)
	{}

	T * get() const 
	{
		return ptr_;
	}

	T * operator->()
	{
		return ptr_;
	}

	T & operator*() const
	{
		return *ptr_;
	}

	~RAII()
	{
		std::cout << "~RAII()" << std::endl;
		delete ptr_;
	}

private:
	RAII(const RAII &rhs);
	RAII &operator=(const RAII &rhs);

private:
	T *ptr_;
};

class SomeResource
{
public:
	SomeResource()
		: inum_(10)
	{
		std::cout << "SomeResource()" << std::endl;
	}

	SomeResource(int inum)
		: inum_(inum)
	{
		std::cout << "SomeResource(int)" << std::endl;
	}

	~SomeResource()
	{
		std::cout << "~SomeResource() inum = " << inum_ << std::endl;
	}

private:
	int inum_;
};

class Example
{
public:
	Example()
		: someRsPtr1_(new SomeResource),
		  someRsPtr2_(new SomeResource(20))
	{
		std::cout << "Example()" << std::endl;
	}

	Example(const Example &rhs)
		:someRsPtr1_(new SomeResource(*rhs.someRsPtr1_)),
		 someRsPtr2_(new SomeResource(*rhs.someRsPtr2_))
	{}

	Example & operator=(const Example &rhs)
	{
		if(this != &rhs)
		{
			*someRsPtr1_ = *rhs.someRsPtr1_;
			*someRsPtr2_ = *rhs.someRsPtr2_;
		}
		return *this;
	}

private:
	RAII<SomeResource> someRsPtr1_;
	RAII<SomeResource> someRsPtr2_;
};

int main(void)
{
	{
	Example ep1;
	}
	while(1){}
}
