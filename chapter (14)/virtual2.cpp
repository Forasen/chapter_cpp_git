

#if 0
/*
多重继承，不带虚拟继承时

1. 每个基类都有自己的虚表
2. 派生类的虚成员函数被加入到第一个基类的虚函数表中
3. 内存布局中，其基类布局依次按其声明时的顺序进行排列
4. 派生类会覆盖掉基类的对应的虚函数，第一个虚函数表中的   被覆盖的虚函数地址是真实的；之后的虚函数表中对应的   被覆盖的虚函数所存放的并不是虚函数的地址，而是一条跳转指令
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