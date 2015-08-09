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
	
void Buffer::push(int no)
{
	MutexLockGuard mtg(mutex_);
	while(full())
	{
		notFull_.wait();	
	}

	que_.push(no);
	notEmpty_.notify();
}

int Buffer::pop()
{
	MutexLockGuard mtg(mutex_);
	while(empty())
	{
		notEmpty_.wait();
	}

	int num = que_.front();
	que_.pop();
	return num;
}

bool Buffer::empty()
{
	return que_.empty();
}

bool Buffer::full()
{
	return maxSize_ == que_.size();
}

}
