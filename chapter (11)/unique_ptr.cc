/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <memory>
#include <vector>


std::unique_ptr<int> getVal()
{
	std::unique_ptr<int> up(new int(66));
	return up;
}

int main(void)
{
	std::unique_ptr<int> ap(new int(99));
	std::unique_ptr<int> two;

	std::cout << "*ap = " << *ap << std::endl;
	std::cout << "ap.get() = " 
		<< reinterpret_cast<long>(ap.get()) << std::endl
		<< std::endl;

	std::unique_ptr<int> up = getVal();
									   //没有调用复制构造函数
	std::cout << "*up = " << *up << std::endl;

	std::unique_ptr<int> sp(new int(55));
	std::vector<std::unique_ptr<int> > vec;
	vec.push_back(std::move(sp));
	std::cout << *vec[0] << std::endl;

	return 0;
}

