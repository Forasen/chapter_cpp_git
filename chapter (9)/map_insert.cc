/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <map>
#include <string>

using std::map;
using std::multimap;
using std::string;
using std::cout;
using std::endl;
using std::pair;


int test0(void)
{
	std::pair<int, std::string> pairs[2] = {
		std::pair<int, std::string>(1, "A"),
		std::pair<int, std::string>(2, "B")
	};

	std::map<int, std::string> map_istr(pairs, pairs + 2);

	std::pair<int, std::string> t(2, "X");

	pair<map<int, string>::iterator, bool> 
		res = map_istr.insert(t);

	if(res.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "map已包括相同关键字的元素:" 
			 << res.first->first << " "
			 << res.first->second << endl;
	}

	return 0;
}


int test1(void)
{
	pair<int, string> pairs[4] = {
		pair<int, string>(7, "G"),
		pair<int, string>(3, "C"),
		pair<int, string>(5, "E"),
		pair<int, string>(1, "A")
	};

	pair<int, string> t(1, "X");
	map<int, string> map_istr(pairs, pairs + 4);

	map<int, string>::iterator mit = map_istr.begin();
	++mit;
	map<int, string>::iterator mit2 = map_istr.insert(mit, t);
	for(mit = map_istr.begin(); mit != map_istr.end(); ++mit)
	{
		cout << mit->first << " " << mit->second << endl;
	}
	cout << "插入t之后：" << endl;
	cout << mit2->first << " " << mit2->second << endl;
}
int main(void)
{
	pair<int, string> pairs[4] = {
		pair<int, string>(7, "G"),
		pair<int, string>(3, "C"),
		pair<int, string>(5, "E"),
		pair<int, string>(1, "A")
	};

	pair<int, string> t(1, "X");
	multimap<int, string> map_istr(pairs, pairs + 4);

	multimap<int, string>::iterator mit = map_istr.begin();
	++mit;
	multimap<int, string>::iterator mit2 = map_istr.insert(mit, t);
	
	multimap<int, string>::const_iterator cmit = map_istr.begin();
	for(; cmit != map_istr.end(); ++cmit)
	{
		cout << cmit->first << " " << cmit->second << endl;
	}
	cout << "插入t之后：" << endl;
	cout << mit2->first << " " << mit2->second << endl;
}
