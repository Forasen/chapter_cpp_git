/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class String
{
public:
	String()
	{
		pStr_ = new char[1];
	}

	void print()
	{
		std::cout << pStr_ << std::endl;
	}

private:
	char *pStr_;
};

int main(void)
{
	String s1;
	s1.print();

	std::cout << "hello,world" << std::endl;
}
