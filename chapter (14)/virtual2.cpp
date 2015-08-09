

#if 0
/*
���ؼ̳У���������̳�ʱ

1. ÿ�����඼���Լ������
2. ����������Ա���������뵽��һ��������麯������
3. �ڴ沼���У�����಼�����ΰ�������ʱ��˳���������
4. ������Ḳ�ǵ�����Ķ�Ӧ���麯������һ���麯�����е�   �����ǵ��麯����ַ����ʵ�ģ�֮����麯�����ж�Ӧ��   �����ǵ��麯������ŵĲ������麯���ĵ�ַ������һ����תָ��
*/



#include <iostream>

class Base1
{
public:
	Base1() : iBase1_(10){}

	virtual void f(){	std::cout << "Base1::f()" << std::endl;	}
	virtual void g(){	std::cout << "Base1::g()" << std::endl;	}
	virtual void h(){	std::cout << "Base1::h()" << std::endl;	}

private:
	int iBase1_;
};

class Base2
{
public:
	Base2() : iBase2_(100){}

	virtual void f(){	std::cout << "Base2::f()" << std::endl;	}
	virtual void g(){	std::cout << "Base2::g()" << std::endl;	}
	virtual void h(){	std::cout << "Base2::h()" << std::endl;	}

private:
	int iBase2_;
};


class Base3
{
public:
	Base3() : iBase3_(1000){}

	virtual void f(){	std::cout << "Base3::f()" << std::endl;	}
	virtual void g(){	std::cout << "Base3::g()" << std::endl;	}
	virtual void h(){	std::cout << "Base3::h()" << std::endl;	}

private:
	int iBase3_;
};


class Derived : public Base1, public Base2, public Base3
{
public:
	Derived() : iDerived_(10000){}

	virtual void f(){	std::cout << "Derived::f()" << std::endl;	}
	virtual void g1(){	std::cout << "Derived::g1()" << std::endl;	}

private:
	int iDerived_;
};

int main(void)
{
	Derived d;

	return 0;
}

#endif