/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include <stdio.h>
#include <iostream>
#include <string>

int main(void)
{
	char buf[1024] = {0};
	char *pstr = "Hello,world";

	std::string s1 = "wahaha";
	std::string s2("123");
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::string s3 = s1 + s2;
	std::cout << "s3 = " << s3 << std::endl;
	
	char ch = 'A';
	std::string s4 = s3 + ch;
	std::cout << "s4 = " << s4 << std::endl;


	int a = 3;
	int b(4);
	int c = a + b;
	std::cout << "c = " << c << std::endl;
	std::cout << std::endl;

	int sz = s4.size();
	for(int idx = 0; idx != sz; ++idx)
	{
		std::cout << s4[idx] << std::endl;
	}
	std::cout << std::endl;

	std::string::iterator it = s4.begin();
	for(; it != s4.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::string substr = s4.substr(0, 7);
	std::cout << "s4's substr = " << substr << std::endl;

}

