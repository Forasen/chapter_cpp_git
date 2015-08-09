/*******************************
 *@fileName: lhs_rhs.cc
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-06-23 15:15:06
**********************************/
#include <iostream>
#include <vector>


int test0(void)
{
	int a = 10; 
	int b = 120;
	int *pFlag = &a;
	std::vector<int> vec;
	vec.push_back(1);
	std::string str1 = "hello";
	std::string str2 = "world";
	const int &m = 1;

	//int *pc = &(a + b);// a+b 右值
	//int *pc = &a++;//a++  返回的是一个临时对象，右值
	int *pc = &++a;//++a左值
	int **pd = &pFlag;
	int *p1 = &*pFlag;//左值
	int *p2 = &vec[0];//左值

	//int *p3 = &100;//右值
	//&std::string("hello");//右值
#if 0
	Point arr[2] = {
		Point(1, 2), 
		Point(3, 4)
	};

	//通过类名加上构造函数的参数列表，来创建的对象都是临时对象
#endif

	//&(str1 + str2);//右值

}

int && getvalue()
{
	return 2;
}


int main(void)
{
	int a = 10;
	//int &refa = 10;
	int &refa = a;//非常量左值引用只能绑定到非常量左值
	const int &refb = 10;

	int &&refc = 10;//右值引用
	//int &&refd = a;//右值引用不能绑定到左值

	getvalue();//这时的右值引用是右值
	int &&refe = getvalue();//getvalue()就是一个左值
}
