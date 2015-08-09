/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "Buffer.h"
#include <iostream>

namespace wd
{

Buffer::Buffer(std::size_t num)
	: notFull_(mutex_),
	  notEmpty_(mutex_),
	  maxSize_(num)
{
	std::cout <<"Buffer::Buffer(int)" << std::endl;
}

Buffer::~Buffer()
{
	std::cout <<"Buffer::~Buffer()" << std::endl;
}
	
void Buffer::push(Task *ptask)
{
	MutexLockGuard mtg(mutex_);
	while(full())
	{
		notFull_.wait();	
	}

	que_.push(ptask);
	notEmpty_.notify();
}

Task *Buffer::pop()
{
	MutexLockGuard mtg(mutex_);
	while(empty())
	{
		notEmpty_.wait();
	}

	Task *ptask = que_.front();
	que_.pop();
	notFull_.notify();
	return ptask;
}

bool Buffer::empty()
{
	return que_.empty();
}

bool Buffer::full()
{
	return maxSize_ == que_.size();
}

}//end of namespace wd
