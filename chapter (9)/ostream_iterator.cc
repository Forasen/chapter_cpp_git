/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main(void)
{
	int arr[6] = {1, 2, 3, 4, 5, 6};
	std::vector<int> int_vec(arr, arr + 6);

	std::ostream_iterator<int> osi(std::cout, "\n");
	copy(int_vec.begin(), int_vec.end(), osi);

	return 0;
}
