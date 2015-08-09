/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class NullPointerCall
{
public:
	static void test1();
	void test2();
	void test3(int itest);
	void test4();
private:
	static int iStatic_;
	int iTest_;
};

int NullPointerCall::iStatic_ = 10;


void NullPointerCall::test1()
{
	std::cout << "iStatic_ = " << iStatic_<< std::endl;
}

void NullPointerCall::test2()
{
	std::cout << "very cool!" << std::endl;
}

void NullPointerCall::test3(int itest)
{
	std::cout << "itest = " << itest << std::endl;
}

void NullPointerCall::test4()
{
	std::cout << "iTest_ = " << iTest_ << std::endl;
}

int main(void)
{
	NullPointerCall *p = NULL;
	p->test1();
	p->test2();
	p->test3(3);
	p->test4();

	return 0;
}
