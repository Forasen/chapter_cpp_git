/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>

class String
{
public:
	String()
	{
		std::cout << "String()" << std::endl;
		pstr_ = new char[1];
	}

	String(const char *pstr)
	{
		std::cout << "String(const char *pstr)" << std::endl;
		pstr_ = new char[strlen(pstr) + 1];
		strcpy(pstr_, pstr);
	}

	String(const String &rhs)//复制构造函数
	{
		std::cout << "String(const String&)" << std::endl;
		pstr_ = new char[strlen(rhs.pstr_) + 1];
		strcpy(pstr_, rhs.pstr_);
	}

	String(String &&rhs)
		:pstr_(rhs.pstr_)
	{
		std::cout << "String(String &&rhs)" << std::endl;	
		rhs.pstr_ = NULL;
	}

	String &operator=(const String &rhs)
	{
		std::cout << "String&operator=(const String&)" << std::endl;
		if(this != &rhs)
		{
			delete [] pstr_;
			pstr_ = new char[strlen(rhs.pstr_) + 1];
			strcpy(pstr_, rhs.pstr_);
		}
		return *this;
	}

	String &operator=(String &&rhs)
	{
		std::cout << "String &operator=(String &&rhs)" << std::endl;
		if(this != &rhs)
		{
			delete [] pstr_;
			pstr_ = rhs.pstr_;
			rhs.pstr_ = NULL;
		}
		return *this;
	}


	String & operator +=(const String &rhs)
	{
		std::cout << "String &operator +=(const String&rhs)" << std::endl;
		int len = strlen(pstr_) + strlen(rhs.pstr_) + 1;
		char * ptmp = new char[len + 1];
		strcpy(ptmp, pstr_);
		strcat(ptmp, rhs.pstr_);

		return *this;
	}

	~String()
	{
		std::cout << "~String()" << std::endl;
		delete []pstr_;
	}
	friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
	char *pstr_;
};


String operator+(const String &lhs, const String &rhs)
{
	std::cout << "String operator + (const String &lhs, const String &rhs)" << std::endl;
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

String operator+(const String &lhs, const char *rhs)
{
	std::cout << "String operator+(const String &, const char*)" << std::endl;
	String tmp(rhs);
	tmp += lhs;
	return tmp;
}

String operator+(const char *lhs, const String &rhs)
{
	std::cout << "String operator+(const char *lhs, const String &rhs)" << std::endl;
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
	os << rhs.pstr_;
	return os;
}
String getStr()
{
	String s1 = "hello";
	return s1;
}

int main(void)
{
	String s1 = "hello";

	return 0;
}
