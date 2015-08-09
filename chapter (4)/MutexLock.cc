/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <unistd.h>

class MutexLock
{
public:
	MutexLock() : isLocking_(false)
	{
		std::cout << "MutexLock()" << std::endl;
		pthread_mutex_init(&mutex_, NULL);
	}

	void lock()
	{
		std::cout << "lock()" << std::endl;
		pthread_mutex_lock(&mutex_);
		isLocking_ = true;
	}

	void unlock()
	{
		std::cout << "unlock()" << std::endl;
		pthread_mutex_unlock(&mutex_);
		isLocking_ = false;
	}

	bool isLocked()
	{
		return isLocking_;
	}

	~MutexLock()
	{
		std::cout << "~MutexLock() " << std::endl;
		pthread_mutex_destroy(&mutex_);
	}

private:
	MutexLock(const MutexLock &rhs);
	MutexLock & operator=(const MutexLock &rhs);
private:
	pthread_mutex_t mutex_;
	bool isLocking_;
};

int main(void)
{
	MutexLock mutex;

	mutex.lock();
	sleep(3);
	mutex.unlock();
	

	return 0;
}
