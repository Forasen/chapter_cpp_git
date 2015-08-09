/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <algorithm>

void printElements(std::list<int> &c)
{
	std::list<int>::const_iterator cit = c.begin();
	while(cit != c.end())
	{
		std::cout << *cit++ << " ";
	}
}

int main(void)
{
	std::vector<int> int_vec;
	std::list<int> int_list;
	for(std::vector<int>::size_type idx = 0; idx < 3; ++idx)
	{
		int_vec.push_back(idx);
	}

	copy(int_vec.begin(), int_vec.end(),
			std::back_insert_iterator<std::list<int> >(int_list));
	printElements(int_list);
	std::cout << std::endl;

	copy(int_vec.begin(), int_vec.end(),
			std::front_insert_iterator<std::list<int> >(int_list));
	printElements(int_list);
	std::cout << std::endl;


	copy(int_vec.begin(), int_vec.end(), 
			std::insert_iterator<std::list<int> >(int_list, 
				++int_list.begin()));

	printElements(int_list);

	
	std::cout << std::endl;

	return 0;
}
