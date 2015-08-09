/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <fstream>
#include <string>

int test0(void)
{
	std::ofstream ofs("test.txt", std::ios::app);
	if(!ofs.good())
	{
		std::cout << "ofstream error" << std::endl;
		return -1;
	}

	std::cout << "文件流指针当前的位置: " << ofs.tellp() << std::endl;
	
	ofs << "\nthat's new" << std::endl;
	ofs.close();
	return 0;

}

int test1(void)
{
	test0();
	std::ifstream ifs("test.txt", std::ios::ate);
	if(!ifs.good())
	{
		std::cout << "ifstream error" << std::endl;
		return -1;
	}

	std::cout << "文件流指针当前的位置: " << ifs.tellg() << std::endl;

	ifs.close();
	return 0;
}

int main(void)
{
	std::fstream fs("fs.dat", std::ios::out | std::ios::in);
	if(!fs.good())
	{
		std::cout << "fstream error" << std::endl;
		return -1;
	}

	int ival;
	for(int idx = 0; idx != 10; ++idx)
	{
		std::cin >> ival;
		fs << ival << ' ';
	}

	std::cout << fs.tellg() << std::endl;
	fs.seekg(0, std::ios::beg);
	for(int idx = 0; idx != 10; ++idx)
	{
		fs >> ival;
		std::cout << ival << ' ';
	}

	std::cout << std::endl;

	fs.close();
	return 0;
}
