/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	std::vector<int> vecInt;
	std::cout << "vecInt的元素个数:"
			  << vecInt.size() 
			  << std::endl;

	double darr[6] = {1, 2, 3, 4, 5, 6};
	std::deque<double> dequeDouble(darr, darr + 5);
	for(int idx = 0; idx != dequeDouble.size(); ++ idx)
		std::cout << dequeDouble[idx] << " ";
	std::cout << std::endl << std::endl;

	std::deque<double>::iterator it;
	for(it = dequeDouble.begin(); it != dequeDouble.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::list<float> listFloat(3, 5);//2.
	std::list<float>::iterator lit;
	for(lit = listFloat.begin(); lit != listFloat.end(); ++lit)
	{
		std::cout << *lit << " ";
	}
	std::cout << std::endl << std::endl;

	std::list<float> listFloat2(4, 9);
	listFloat.swap(listFloat2);
	
	for(lit = listFloat.begin(); lit != listFloat.end(); ++lit)
	{
		std::cout << *lit << " ";
	}
	std::cout << std::endl << std::endl;


	std::list<float> listFloat3(listFloat);
	std::list<float>::iterator lit3;
	for(lit3 = listFloat3.begin(); lit3 != listFloat3.end(); ++lit3)
	{	
		std::cout << *lit3 << " "; 
	}
	std::cout << std::endl << std::endl;
	return 0;
}

