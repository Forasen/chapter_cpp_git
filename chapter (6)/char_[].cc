/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>

class CharArray
{
public:
	CharArray(int size)
		: iLen_(size) 
	{
		pbuf = new char[iLen_];
	}

	~CharArray()
	{
		delete pbuf;
	}

	int getlen()
	{	return iLen_;	}

	char & operator[](int idx);
private:
	int iLen_;
	char *pbuf;
};
char & CharArray::operator[](int idx)
{
	static char null_char = '\0';
	if(idx >= 0 || idx < iLen_)
	{
		return pbuf[idx];
	}
	else
	{
		std::cout << "超出下标的范围" << std::endl;
		return null_char;
	}
}


int main(void)
{
	char *pstr = "hello,world";
	int len = strlen(pstr) + 1;
	CharArray ca(len);

	for(int idx = 0; idx != len; ++idx)
	{
		ca[idx] = pstr[idx];
	}

	for(int idx = 0; idx != len; ++idx)
	{
		std::cout << ca[idx] << std::endl;
	}
	std::cout << std::endl;


	std::string s1 = "wangdao";
	for(int idx = 0; idx != s1.size(); ++idx)
	{
		std::cout << s1[idx];
	}

	return 0;
}
