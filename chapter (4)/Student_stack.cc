/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>

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

private:
	static void * operator new(std::size_t nSize);

	static void operator delete(void *pVoid);

private:
	int iId_;
	char szName_[128];
};

int main(void)
{
	Student s1;
	s1.setId(100);
	s1.setName("zhangsan");
	
}
