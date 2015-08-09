/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <stdio.h>
#include <string.h>

class String
{
public:
	String()
	{
		std::cout << "String()" << std::endl;
		pstr_ = new char[1];
	}

	String(const char * pstr)
	{
		std::cout << "String(const char*)" << std::endl;
		pstr_ = new char[strlen(pstr) + 1];
		strcpy(pstr_, pstr);
	}

	String(const String & rhs)
	{
		std::cout << "String(const String &) " << std::endl;
		pstr_ = new char [strlen(rhs.pstr_) + 1];
		strcpy(pstr_, rhs.pstr_);
	}

	String & operator=(const String & rhs)
	{
		std::cout << "operator=(const String&)" << std::endl;
		if(this != &rhs)
		{
			delete []pstr_;
			pstr_ = new char[strlen(rhs.pstr_) + 1];
			strcpy(pstr_, rhs.pstr_);
		}
		return *this;
	}
	
	~String()
	{
		std::cout << "~String()" << std::endl;
		delete pstr_;
	}
	
	void print()
	{
		printf("%s\n", pstr_);
	}

private:
	char * pstr_;
};

int main(void)
{
	String s1;
	String s2 = "wangdao"; 
	String s3 = s2;
	
	s1.print();
	s2.print();
	s3.print();
	s1 = s3;
	s1.print();

	std::cout << "hello, world" << std::endl;
	return 0;
}
