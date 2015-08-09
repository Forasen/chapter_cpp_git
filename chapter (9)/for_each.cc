/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print(vector<int>::value_type value)
{
	++value;
	cout << value << " ";
}

void print2(vector<int>::value_type value)
{
	cout << value << " ";
}

int main(void)
{
	int arr[6] = {1, 2 ,3 ,4, 5, 6};
	vector<int> int_vec(arr, arr + 6);
	for_each(int_vec.begin(), int_vec.end(), print);
	cout << endl;
	for_each(int_vec.begin(), int_vec.end(), print2);
	cout << endl;

	for(auto a : int_vec)
	{
		cout << a << " ";
	}
	cout << endl;

	return 0;
}
