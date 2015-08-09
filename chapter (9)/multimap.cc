/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <map>

int main(void)
{
	std::pair<int, std::string> pairs[4] = {
		std::pair<int, std::string>(9, "Asia"),
		std::pair<int, std::string>(4, "Africa"),
		std::pair<int, std::string>(1, "Euro"),
		std::pair<int, std::string>(4, "America")
	};

	std::multimap<int, std::string> mmap_istr(pairs, pairs + 4);

	std::multimap<int, std::string>::iterator mit;
	for(mit = mmap_istr.begin(); mit != mmap_istr.end(); ++mit)
	{
		std::cout << mit->first << " " << mit->second << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
