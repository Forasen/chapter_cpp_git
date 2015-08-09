/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class SomResource
{
private:
	int inum_;
};

class Example
{
public:
	Example()
		: p1_(new SomeResource),
		  p2_(new SomeResource)
	{
		std::cout << "Example()" << std::endl;
	}

	Example(const Example &rhs)
		:p1_(new SomeResource(*rhs.p1_)),
		 p2_(new SomeResource(*rhs.p2_))
	{}

	Example & operator=(const Example &rhs)
	{
		if(this != rhs)
		{
			*p1_ = *rhs.p1_;
			*p2_ = *rhs.p2_;
		}
		return *this;
	}

	~Example()
	{
		std::cout << "~Example()" << std::endl;
		delete p1_;
		delete p2_;
	}


private:
	SomeResource *p1_;
	SomeResource *p2_;
};


int main(void)
{
	Example ep1;
}
