/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <cstring>  
using namespace std;

extern int num = 0;

namespace B
{
	int num = 2;
}


int func()
{
	return 3; 
}

namespace A
{
	int num = 1;
	void displayA()
	{
		int num = 3;
		cout << "displayA中的num:" << num << endl;

		cout << "A中的num: " << A::num << endl;

		cout << "B中的num: " << B::num << endl;

		cout << "外部的num: " << ::num << endl;

		cout << "call func() = " << ::func() << endl; 

	}
}

namespace B
{
	void displayB()
	{
		A::displayA();
	}
}

int main(void)
{
	A::displayA();
	B::displayB();

	return 0;
}
