/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <iterator>
#include <vector>

int main(void)
{
	std::vector<int> int_vec;

	std::istream_iterator<int> isi(std::cin);

	copy(isi, std::istream_iterator<int>(), back_inserter(int_vec));

	std::vector<int>::const_reverse_iterator it;
	for(it = int_vec.rbegin(); it != int_vec.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}
