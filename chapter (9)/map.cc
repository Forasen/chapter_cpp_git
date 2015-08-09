/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <map>

int main(void)
{
	std::pair<const int, std::string> t(600036, "招商银行");
	std::cout << t.first << " " << t.second << std::endl;

	std::pair<int, std::string> pairs[4] = {
		std::pair<int, std::string>(9, "Asia"),
		std::pair<int, std::string>(4, "Africa"),
		std::pair<int, std::string>(1, "Euro"),
		std::pair<int, std::string>(4, "America")
	};

	std::map<int, std::string> map_istr(pairs, pairs + 4);

	std::map<int, std::string>::iterator mit;
	for(mit = map_istr.begin(); mit != map_istr.end(); ++mit)
	{
		std::cout << mit->first << " " << mit->second << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
