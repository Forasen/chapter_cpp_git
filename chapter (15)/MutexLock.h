/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_MUTEXLOCK_H
#define _WD_MUTEXLOCK_H

#include "Noncopyable.h"
#include <pthread.h>
namespace wd
{

class MutexLock : public Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	bool isLocked() const;
	pthread_mutex_t *getMutexPtr();

private:	
	pthread_mutex_t mutex_;
	bool isLocking_;
};//end of class MutexLock


class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex);

	~MutexLockGuard();

private:
	MutexLock &mutex_;
};

}//end of namespace wd


#endif
