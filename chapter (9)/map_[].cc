/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;
using std::pair;
using std::cout;
using std::endl;

int main(void)
{
	pair<string, string> pairs[4] = {
		pair<string, string>("a", "xiaoming"),
		pair<string, string>("c", "xiaohong"),
		pair<string, string>("e", "xiaogang"),
		pair<string, string>("f", "xiaohua")
	};	

	map<string, string> map_str(pairs, pairs + 4);

	std::cout << map_str["c"] << std::endl;

	map_str["g"] = "wangdao";

	map<string, string>::const_iterator mit;
	for(mit = map_str.begin(); mit != map_str.end(); ++mit)
	{
		cout << mit->first << " " << mit->second << endl;
	}
	cout << endl;

}

