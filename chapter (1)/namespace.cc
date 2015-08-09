/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

using std::cout;
using std::endl;

namespace wangdao
{
	int num = 1;
	int add(int a, int b)
	{
		return a + b;
	}


	namespace A
	{
		int num = 2;
	}
}

namespace C
{
	void displayC()
	{
		cout << "This is C" << endl;
	}
}

namespace D
{
	void displayD()
	{
		cout << "This is D" << endl;
	}
}

int func()
{
	using wangdao::A::num;
	cout << "wangdao::A::num = " << num << endl;

}

int main(void)
{

	cout << "wangdao::num = " << wangdao::num << endl;

	func();

	 return 0;
}
