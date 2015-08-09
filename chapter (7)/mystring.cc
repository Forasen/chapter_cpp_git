/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <stdio.h>
#include <iostream>
#include <string.h>

class String
{
public:
	String();
	String(const char * str);
	String(const String &rhs);
	String &operator=(const String &rhs);
	~String();

	const char *c_str()const
	{
		return pstr_;
	}

	int use()
	{
		int len = strlen(pstr_);
		return pstr_[len + 1];
	}


	char & operator[](int idx);
	const char & operator[](int idx) const;

	friend std::ostream & operator<<(std::ostream &os, String &rhs);

private:
	char *pstr_;
};

std::ostream & operator<<(std::ostream &os, String &rhs)
{
	os << rhs.pstr_;
	return os;
}
String::String()
{
	pstr_ = new char[2];
	pstr_[1] = 1;
}

String::String(const char * str)
{
	int len = strlen(str);
	pstr_ = new char[len + 2];
	pstr_[len + 1] = 1;
	strcpy(pstr_, str);
}

String::String(const String &rhs)
{
	int len = strlen(rhs.pstr_);
	pstr_ = rhs.pstr_;
	++pstr_[len + 1];
}


String & String::operator=(const String &rhs)
{
	if(this != &rhs)
	{
		int len = strlen(pstr_);
		if(--pstr_[len + 1] == 0)
		{
			delete []pstr_;
		}
		
		pstr_ = rhs.pstr_;
		len = strlen(pstr_);
		++pstr_[len + 1];
	}
	return *this;
}

String::~String()
{
	
	int len = strlen(pstr_);
	if(--pstr_[len + 1] == 0)
	{
		std::cout << "delete []pstr_" << std::endl;
		delete []pstr_;
	}
}

char & String::operator[](int idx)
{
	static char nullchar = '\0';
	int len = strlen(pstr_);
	if(idx < len || idx >= 0)
	{
		if(--pstr_[len + 1] != 0)
		{
			char *ptmp = new char[len + 2];
			strcpy(ptmp, pstr_);
			pstr_ = ptmp;
			pstr_[len + 1] = 1;
		}
		else
		{
			++pstr_[len + 1];
		}

		return pstr_[idx];
	}
	else{
		std::cout << "ilegal argument" << std::endl;
		return nullchar;
	}
}

int main(void)
{
	String s1;
	std::cout << s1 << std::endl;

	String s2 = "hello,world!";
	std::cout << "s2 = " << s2 << ", use = " << s2.use() << std::endl;

	String s3 = s2;
	std::cout << s3 << std::endl;
	std::cout << "s3 = " << s3 << ", use = " << s3.use() << std::endl;
	const char *ps2 = s2.c_str();
	const char *ps3 = s3.c_str();
	printf("ps2 = %x\n", ps2);
	printf("ps3 = %x\n", ps3);

	std::cout << s3[0] << std::endl;
	std::cout << "s3发生读操作之后" << std::endl;
	std::cout << "s2 = " << s2 << ", use = " << s2.use() << std::endl;
	std::cout << "s3 = " << s3 << ", use = " << s3.use() << std::endl;
	ps3 = s3.c_str();
	printf("ps2 = %x\n", ps2);
	printf("ps3 = %x\n", ps3);

	const String s4 = "wangdao";
	s4[0];

	return 0;
}
