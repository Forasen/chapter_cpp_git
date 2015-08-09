/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <queue>
#include <functional>

int test(void)
{
	int arr[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7,4};
	std::priority_queue<int> pri_que;
	for(int idx = 0; idx != 10; ++idx)
	{
		pri_que.push(arr[idx]);
		std::cout << pri_que.top()
			<< "是目前该队列中优先级别最高的" << std::endl;
	}

	std::cout << "现在的priority_queue的容量是:" 
			  << pri_que.size() << std::endl;


	for(int idx = 0; idx != 10; ++idx)
	{
		std::cout << pri_que.top() 
			<< "准备出队列" << std::endl;
		pri_que.pop();
	}

	std::cout << "现在的priority_queue的容量是:" 
			  << pri_que.size() << std::endl;

	return 0;
}

int main(void)
{

	int arr[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7,4};
	std::priority_queue<int, std::vector<int>, std::greater<int> > gpri_que;

	for(int idx = 0; idx != 10; ++idx)
	{
		gpri_que.push(arr[idx]);
		std::cout << gpri_que.top()
			<< "是目前该队列中优先级别最高的" << std::endl;
	}

	std::cout << "现在的priority_queue的容量是:" 
			  << gpri_que.size() << std::endl;


	for(int idx = 0; idx != 10; ++idx)
	{
		std::cout << gpri_que.top() 
			<< "准备出队列" << std::endl;
		gpri_que.pop();
	}

	std::cout << "现在的priority_queue的容量是:" 
			  << gpri_que.size() << std::endl;
}
