/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Base
{
protected:
	Base(int ix = 0)
		: ix_(ix)
	{}

public:
	void display()
	{
		std::cout << "Base::ix_ = " << ix_ << std::endl;
	}

private:
	int ix_;
};


class Child: public Base
{
public:
	Child(int ix)
		: Base(ix),
	{}
};


int main(void)
{
	Child c(1);
	c.display();
}
