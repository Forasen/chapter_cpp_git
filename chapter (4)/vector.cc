/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <vector>

void printSize(std::vector<int> & vec)
{
	std::cout << "vec's size = " << vec.size() << std::endl;
	std::cout << "vec's capacity = " << vec.capacity() << std::endl;
}

int main(void)
{
	//int arr[10];
	int a =10;
	std::vector<int> vec;
	printSize(vec);

	vec.push_back(1);
	printSize(vec);
	vec.push_back(2);
	printSize(vec);
	vec.push_back(3);
	printSize(vec);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(a);
	printSize(vec);

	int sz = vec.size();
	for(int idx = 0; idx != sz; ++idx)
	{
		std::cout << vec[idx] << std::endl;
	}
	std::cout << std::endl;
	vec[5] = 11;

	std::vector<int>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "a = " << a << std::endl;

}
