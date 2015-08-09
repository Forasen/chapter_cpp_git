/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <stdio.h>
#include <iostream>
#include <string.h>

class String
{
	friend std::ostream & operator<<(std::ostream &os, String &rhs);
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


private:
	class CharProxy
	{
	public:
		CharProxy(String & str, int idx);
		CharProxy & operator=(char c);
		operator char() const;

	private:
		String  &theString_;
		int charIdx_;
	};
public:
	friend CharProxy;

	CharProxy operator[](int idx);
	const CharProxy operator[](int idx) const;

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

String::CharProxy String::operator[](int idx)
{
	return CharProxy(*this, idx);
}

const String::CharProxy String::operator[](int idx) const
{
	return CharProxy(const_cast<String &>(*this), idx);
}

String::CharProxy::CharProxy(String & str, int idx)
	: theString_(str),
	  charIdx_(idx)
{}

String::CharProxy & String::CharProxy::operator=(char c)
{
	int len = strlen(theString_.pstr_);
	if(charIdx_ < len && charIdx_ >= 0)
	{
		if(--(theString_.pstr_[len + 1]) != 0)
		{
			char *ptmp = new char[len + 2];
			strcpy(ptmp, theString_.pstr_);
			theString_.pstr_ = ptmp;
			theString_.pstr_[len + 1] = 1;
		}
		else
		{
			theString_.pstr_[len + 1] = 1;
		}
		theString_.pstr_[charIdx_] = c;
	}	
	else
	{
		std::cout << "index 越界" << std::endl;
	}
	return *this;
}

String::CharProxy::operator char()const
{
	static char nullchar = '\0';
	int len = strlen(theString_.pstr_);
	if(charIdx_ < len && charIdx_ >=0)
		return theString_.pstr_[charIdx_];
	else
	{
		std::cout << "index 越界" << std::endl;
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


	std::cout << s3[20] << std::endl;
	std::cout << "s3发生读操作之后" << std::endl;
	std::cout << "s2 = " << s2 << ", use = " << s2.use() << std::endl;
	std::cout << "s3 = " << s3 << ", use = " << s3.use() << std::endl;
	ps3 = s3.c_str();
	printf("ps2 = %x\n", ps2);
	printf("ps3 = %x\n", ps3);

	return 0;
}
