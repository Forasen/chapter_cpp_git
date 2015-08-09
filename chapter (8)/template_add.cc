/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string>
#include <string.h>

template <typename T>
T add(const T & a, const T & b)
{
	return a + b;
}

template<>
const char *add<const char*>(const char * const & pa, const char *const & pb)
{
	int len = strlen(pa) + strlen(pb) + 1;
	char *pret = new char[len + 1];
	strcpy(pret, pa);
	strcat(pret, pb);
	return pret;
}

int main(void)
{
	std::cout << add(10, 20) << std::endl;
	std::cout << add(1.0, 2.0) << std::endl;

	std::string x("Hello"), y(",world");
	std::cout << add(x, y) << std::endl;

	const char *pa = "hello";
	const char *pb = "world";
	add(pa,pb);


	return 0;
}



