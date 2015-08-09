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

namespace wd
{
class Buffer : public Noncopyable
{
public:
	Buffer(std::size_t num);
	~Buffer();

	void push(int no);

	int pop();

	bool empty();
	bool full();

private:
	MutexLock mutex_;
	Condition notFull_;
	Condition notEmpty_;

	std::size_t maxSize_;
	std::queue<int> que_;
};

}//end of namespac wd

#endif
