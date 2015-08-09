/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

int main(void)
{
	std::cout << "hello,world!" << std::endl;
	
	std::string str;

	while(getline(std::cin, str))
		std::cout << str << std::endl;
}
