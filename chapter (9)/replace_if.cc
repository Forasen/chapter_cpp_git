/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::less;

void print(vector<int>::value_type value)
{
	cout << value << " ";
}

int main(void)
{
	int arr[6] = {1, 2, 3, 4, 5, 6};
	vector<int> int_vec(arr, arr + 6);
	less<int> lt;

	replace_if(int_vec.begin(), int_vec.end(), bind1st(lt, 3), 7);
	for_each(int_vec.begin(), int_vec.end(), print);
	
	cout << endl;
}
