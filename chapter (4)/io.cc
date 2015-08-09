/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string>


void printCin()
{
	std::cout << "bad  = " << std::cin.bad() << std::endl;
	std::cout << "fail = " << std::cin.fail() << std::endl;
	std::cout << "eof  = " << std::cin.eof() << std::endl;
	std::cout << "good = " << std::cin.good() << std::endl;
}


int main(void)
{
	printCin();
	
	int inum;
	while(std::cin >> inum)
	{
		std::cout << inum << std::endl;
	}

	printCin();

	std::cin.clear();
	std::cin.ignore(1024, '\n');

	std::cout << std::endl;
	printCin();

	while(std::cin >> inum)
	{
		std::cout << inum << std::endl;
	}
	std::cout << std::endl;
	printCin();
	
}
