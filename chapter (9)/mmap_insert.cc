/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <map>
#include <string>

using std::multimap;
using std::string;
using std::cout;
using std::endl;
using std::pair;


int main(void)
{
	std::pair<int, std::string> pairs[2] = {
		std::pair<int, std::string>(1, "A"),
		std::pair<int, std::string>(2, "B")
	};

	std::multimap<int, std::string> map_istr(pairs, pairs + 2);

	std::pair<int, std::string> t(2, "X");

	multimap<int, string>::iterator mmit = map_istr.insert(t);
	
	cout << "向multimap插入的元素为:"
		 << mmit->first << " "
		 << mmit->second << endl;

	for(mmit = map_istr.begin(); mmit != map_istr.end(); ++mmit)
	{
		cout << mmit->first << " " << mmit->second << endl;
	}
	cout << endl;

	return 0;
}
