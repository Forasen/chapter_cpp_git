/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/


/*
���ָ����ָ������������ݣ�
1. ���ָ��ĵ�һ�����ݱ�ʾ���Ǹ����ָ��������ڵ��Ӷ�����׵�ַ��ƫ��
2. ���ָ��ĵڶ������ݱ�ʾ���Ǹ����ָ�����������Ӷ�����׵�ַ��ƫ��
*/

#if 0
#pragma vtordisp(off)
#include <iostream>

class B
{
public:
	B() : ib_(10), cb_('B'){}

	virtual void f(){	std::cout << "B::f()" << std::endl;	}
	virtual void bf(){	std::cout << "B::bf()" << std::endl;}
private:
	int ib_;
	char cb_;
};


class B1 : virtual public B
{
public:
	B1() : ib1_(11), cb1_('1'){}

	virtual void f(){	std::cout << "B1::f()" << std::endl;	}
	virtual void f1() {	std::cout << "B1::f1()" << std::endl;	}
	virtual void bf1(){	std::cout << "B1::bf1()" << std::endl;	}

private:
	int ib1_;
	char cb1_;
};

class B2 : virtual public B
{
public:
	B2() : ib2_(11), cb2_('1'){}

	virtual void f(){	std::cout << "B2::f()" << std::endl;	}
	virtual void f2() {	std::cout << "B2::f2()" << std::endl;	}
	virtual void bf2(){	std::cout << "B2::bf2()" << std::endl;	}

private:
	int ib2_;
	char cb2_;
};


class D : public B1, public B2
{
public:
	D() : id_(100), cd_('D'){}

	virtual void f(){	std::cout << "D::f()" << std::endl;	}
	virtual void f1() {	std::cout << "D::f1()" << std::endl;	}
	virtual void f2() {	std::cout << "D::f2()" << std::endl;	}
	virtual void df() {	std::cout << "D::df()" << std::endl;	}

private:
	int id_;
	int cd_;
};


int main(void)
{
	D d;

	return 0;
}

#endif
