/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

template <typename T, int num>
class Stack
{
public:
	Stack() : point_(0){}

	bool isEmpty();
	bool isFull();
	bool push(const T &);
	bool pop(T &);
	int & getpos()
	{	return point_;	}

private:
	T arr_[num];
	int point_;
};


template<typename T, int num>
bool Stack<T, num>::isEmpty()
{
	return (point_ == 0);
}


template<typename T, int num>
bool Stack<T, num>::isFull()
{
	return (point_ == num);
}

template<typename T, int num>
bool Stack<T, num>::push(const T & val)
{
	if(isFull())
	{
		return false;
	}
	else
	{
		arr_[point_++] = val;
		return true;
	}
}

template<typename T, int num>
bool Stack<T, num>::pop(T & val)
{
	if(isEmpty())
		return false;
	else
	{
		--point_;
		val = arr_[point_];
		return true;
	}
}


int main(void)
{
	Stack<int, 10> stackInt;
	std::cout << "开始时 stackInt 是否为空？" 
			  << stackInt.isEmpty() << std::endl;

	stackInt.push(5);
	std::cout << "此时stackInt是否为空？"
			  << stackInt.isEmpty() << std::endl;

	for(int idx = 0; idx != 9; ++idx)
	{
		stackInt.push(idx);
	}

	std::cout << "此时stackInt是否已满？"
		      << stackInt.isFull() << std::endl;

	int rec = 0;
	while(stackInt.pop(rec))
		std::cout << rec << " ";

	std::cout << std::endl;

	return 0;
}
