/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class BaseClass
{
public:
	BaseClass(int ival)
		: ival_(ival)
	{
		std::cout << "BaseClass(int ival) " << std::endl;
	}

	BaseClass()
	{
		std::cout << "BaseClass()" << std::endl;
	}

private:
	int ival_;
};


class DerivedClass : public BaseClass
{
public:
#if 0
	DerivedClass(): //BaseClass()Ĭ�ϻ��Զ�����ȱʡ�Ĺ��캯��
	{
		std::cout << "DerivedClass()" << std::endl;
	}

	DerivedClass(int i)
	{
		std::cout << "DerivedClass(int)" << std::endl;
	}
#endif
	
};

int main(void)
{
	DerivedClass x1;
	DerivedClass x2;
}
