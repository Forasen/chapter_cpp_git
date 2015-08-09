/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#if 0

#pragma vtordisp(off)
#include <iostream>

/*

使用继承与虚继承的区别
1）通过虚继承创建的对象多了一个虚基指针，虚基指针指向的
    是一个虚基表，虚基表里面存放的其中之一是虚基类子对象
	在该对象中的相对位置
2）虚基类子对象存放的位置发生了变化，从最上面的位置移动了
    最下面的位置
*/

class A
{
public:
	A() : ia_(10){}

	virtual void f()
	{	std::cout << "A::f()" << std::endl;	}

private:
	int ia_;
};

class B 
	: public virtual A   //对于B的内存空间：添加一个虚基指针
{
/*  如果派生类拥有自己的虚函数(并不是覆盖),
	它产生的虚指针是位于虚基指针的前面的;
	或者说，一个类如果有自己的虚函数，它在内存中的布局一定是位于最开始的位置，    原因是为了提高访问虚函数的速度
	*/
public:
	B() : ib_(20) {}
	virtual void f()
	{	std::cout << "B::f()" << std::endl;	}
	virtual void bf()
	{	std::cout << "B::bf()" << std::endl;	}
	virtual void bf2()
	{	std::cout << "B::bf2()" << std::endl;	}


private:
	int ib_;
};

int test0(void)
{
	B b;
	return 0;
}

int main(void)
{
	typedef void (*Function)(void);//函数指针 

	B b;
	//int **pVfTable = (int **) &b;

	int pVtable = (*(int *)&b);//虚函数表的首地址
	Function fun = (Function)(*(int *)pVtable);//第一个虚函数的入口地址
	fun();

	int *p = (int *)pVtable;
	++p;
	fun = (Function)(*p);
	fun();

	getchar();
	//system("pause");
	return 0;
}

#endif
