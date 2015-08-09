/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <list>
#include <deque>

using std::list;
using std::cout;
using std::endl;
using std::deque;

int main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	list<int> listInt(arr, arr + 5);
	listInt.push_front(9);

	list<int>::iterator lit;
	for(lit = listInt.begin(); lit != listInt.end(); ++lit)
	{	cout << *lit << " ";	}
	cout << endl << endl;

	listInt.pop_front();
	for(lit = listInt.begin(); lit != listInt.end(); ++lit)
	{	cout << *lit << " ";	}
	cout << endl << endl;

	double darr[6] = {0, 1, 2, 3, 4, 5} ;
	deque<double> dequeDbl(darr, darr + 6);
	double dval_front = dequeDbl.front();
	double dval_back = dequeDbl.back();
	cout << "front: = " << dval_front << endl;
	cout << "back:  = " << dval_back << endl;
	return 0;
}

