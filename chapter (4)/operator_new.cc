/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>

class Student
{
public:
	Student()
	{
		std::cout << "Student::Student()" << std::endl;
	}

	~Student()
	{
		std::cout << "Student::~Student()" << std::endl;
	}

	void setId(int id)
	{
		iId_ = id;
	}

	void setName(const char *str)
	{
		strcpy(szName_, str);
	}

	static void * operator new(std::size_t nSize)
	{
		std::cout << "operator new(size_t)" << std::endl;
		void * pRet = (void *) malloc(nSize);
		return pRet;
	}

	static void operator delete(void *pVoid)
	{
		std::cout << "operator delete" << std::endl;
		free(pVoid);
	}

private:
	int iId_;
	char szName_[128];
};

int main(void)
{
	Student *pstu = new Student;
	pstu->setId(100);
	pstu->setName("zhangsan");

	delete pstu;
	
}
