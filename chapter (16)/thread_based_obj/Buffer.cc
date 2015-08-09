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
	
void Buffer::push(Task task)
{
	MutexLockGuard mtg(mutex_);//执行了加锁操作,它会自动解锁
	while(full())
	{
		notFull_.wait();	
	}

	que_.push(task);//往缓冲区中添加数据
	notEmpty_.notify();//再发一个通知
}

Task Buffer::pop()
{
	MutexLockGuard mtg(mutex_);
	while(empty())
	{
		notEmpty_.wait();
	}

	Task task = que_.front();
	que_.pop();
	notFull_.notify();
	return task;
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
