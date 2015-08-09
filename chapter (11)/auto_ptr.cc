/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <memory>

int main(void)
{
	std::auto_ptr<double> apd(new double(7.77));//apd本身是一个对象
	std::cout << "*apd = " << *apd << std::endl;//重载了operator*运算符
	
	double *pd = new double(8.88);
	std::auto_ptr<double> apd2(pd);
	std::cout << "pd        = " << reinterpret_cast<long>(pd) << std::endl;
	std::cout << "apd.get() = " << reinterpret_cast<long>(apd2.get()) << std::endl;

	std::cout << std::endl;
	int *pi = new int(7);
	std::auto_ptr<int> api1(pi);
	std::auto_ptr<int> api2(api1);//复制,发生所有权的转移,与常规的认识矛盾
	std::cout << "*api2 = " << *api2 << std::endl; 
	std::cout << "*api1 = " << *api1 << std::endl; 

}
