/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main(void)
{
	std::stack<int, std::vector<int> > int_stack;
	for(int idx  = 1; idx != 21; ++idx)
	{
		int_stack.push(idx);
	}

	while(int_stack.size() > 0)
	{
		int top_val = int_stack.top();
		std::cout << top_val << " ";
		int_stack.pop();
	}
	std::cout << std::endl;
	

	std::stack<std::string> str_stack;
	for(char c = 'A'; c < 'Z'; ++c)
	{
		std::string s(2, c);
		str_stack.push(s);
	}

	while(str_stack.size() > 0)
	{
		std::string s = str_stack.top();
		std::cout << s << std::endl;
		str_stack.pop();
	}



	return 0;
}
