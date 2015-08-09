/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_BUFFER_H
#define _WD_BUFFER_H

#include "Noncopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include <queue>
#include <functional>

namespace wd
{

typedef std::function<void()> Task;
class Buffer : public Noncopyable
{
public:
	explicit Buffer(std::size_t num);//explicit防止隐式转换
	~Buffer();

	void push(Task task);

	Task pop();

	bool empty();
	bool full();

private:
	MutexLock mutex_;
	Condition notFull_;
	Condition notEmpty_;

	std::size_t maxSize_;
	std::queue<Task> que_;
};

}//end of namespac wd

#endif
