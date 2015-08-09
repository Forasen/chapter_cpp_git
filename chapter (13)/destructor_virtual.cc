/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Base
{
public:
	Base(int ix = 0)
		: ix_(ix),
		  data_(new char[64])
	{
		std::cout << "Base(int ix)" << std::endl;
	}

	virtual void display()
	{
		std::cout << "Base::ix_ = " << ix_ << std::endl;
	}

	virtual ~Base()
	{
		std::cout << "~Base()" << std::endl;
		delete [] data_;
	}

private:
	int ix_;
	char *data_;
};


class Child: public Base
{
public:
	Child(int ix)
		: Base(ix),
		  pdata_(new char[64])
	{
		std::cout << "Child(int ix)" << std::endl;
	}

	void display()
	{
		std::cout << "Child::display()" << std::endl;
	}

	~Child()
	{
		std::cout << "~Child()" << std::endl;
		delete []pdata_;
	}
private:
	char *pdata_;
};


int main(void)
{
	Base *pBase = new Child(1);
	pBase->display();
	delete pBase;
}
