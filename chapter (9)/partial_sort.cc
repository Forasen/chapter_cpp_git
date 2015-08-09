/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main(void)
{
	int arr[10] = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

	vector<int> int_vec(arr, arr + 10);
	partial_sort(int_vec.begin(), int_vec.begin() + 5, int_vec.end());

	for(int idx = 0; idx != 10; ++idx)
	{
		cout << int_vec[idx] << " ";
	}
	cout << endl;

}
