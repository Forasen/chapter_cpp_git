/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#if 0

#pragma vtordisp(off)
#include <iostream>

/*

ʹ�ü̳�����̳е�����
1��ͨ����̳д����Ķ������һ�����ָ�룬���ָ��ָ���
    ��һ�����������������ŵ�����֮һ��������Ӷ���
	�ڸö����е����λ��
2��������Ӷ����ŵ�λ�÷����˱仯�����������λ���ƶ���
    �������λ��
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
	: public virtual A   //����B���ڴ�ռ䣺���һ�����ָ��
{
/*  ���������ӵ���Լ����麯��(�����Ǹ���),
	����������ָ����λ�����ָ���ǰ���;
	����˵��һ����������Լ����麯���������ڴ��еĲ���һ����λ���ʼ��λ�ã�    ԭ����Ϊ����߷����麯�����ٶ�
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
	typedef void (*Function)(void);//����ָ�� 

	B b;
	//int **pVfTable = (int **) &b;

	int pVtable = (*(int *)&b);//�麯������׵�ַ
	Function fun = (Function)(*(int *)pVtable);//��һ���麯������ڵ�ַ
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
