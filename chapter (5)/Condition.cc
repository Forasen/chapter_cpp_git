/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

class MutexLock
{
public:
	MutexLock()
	{
		pthread_mutex_init(&mutex_, NULL);
	}

	void lock();
	void unlock();
	pthread_mutex_t *getMutexLockPtr()
	{
		return &mutex_;
	}

private:
	pthread_mutex_t mutex_;
};

class Condition
{
public:
	Condition(MutexLock &mutex)
		: mutex_(mutex)
	{}
	void wait()
	{
		pthread_cond_wait(&cond_, mutex_.getMutexLockPtr());
	}

	void notify()
	{
		pthread_cond_signal(&cond_);
	}

	void notifyAll()
	{
		pthread_cond_broadcast(&cond_);
	}


private:
	Condition (const Condition &rhs);
	Condition &operator=(const Condition &rhs);

private:
	pthread_cond_t cond_;
	MutexLock &mutex_;
};


int main(void)
{
	MutexLock mutex;
	Condition cond(mutex);
	mutex.lock();
	cond.wait();
	mutex.unlock();

	return 0;
}
