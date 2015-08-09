/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <vector>
#include <list>
#include <deque>

using std::vector;
using std::list;
using std::deque;
using std::cout;
using std::endl;


void display(vector<int> & vec)
{
	vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++ it)
		cout << *it << " ";
	cout << endl;
}

int test_vec(void)
{
	vector<int> vecInt(5, 0);
	vector<int>::iterator vit = vecInt.end();
	vit = vecInt.insert(vit, 1);
	display(vecInt);
	cout << "*vit = " << *vit << endl;

	vecInt.insert(vit, 2, 3);//insertÎÞ·µ»ØÖµ
	display(vecInt);

	int arr[3] = {7, 8, 9};
	vecInt.insert(vit, arr, arr + 3);
	display(vecInt);
}

void display(list<int> & li)
{
	list<int>::iterator lit;
	for(lit = li.begin(); lit != li.end(); ++lit)
		cout << *lit << " ";
	cout << endl;
}

int main(void)
{
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> listInt(arr, arr + 9);

	display(listInt);
	cout << endl;

	list<int>::iterator lit = listInt.begin();
	++lit;
	lit = listInt.erase(lit);
	display(listInt);
	cout << "*lit = " << *lit << endl;
	
	list<int>::iterator lit2 = listInt.end();
	--lit2;

	lit = listInt.erase(lit, lit2);
	display(listInt);
	
	cout << "*lit = " << *lit << endl;

	lit2 = listInt.end();

	lit = listInt.erase(lit, lit2);
	display(listInt);
	cout << "*lit = " << *lit << endl;

	listInt.clear();
	display(listInt);

}
