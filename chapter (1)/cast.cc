/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

int main(void)
{
	int ival = 10;
	double dval = double (ival);

	double dval2 = static_cast<double>(ival);
	std::cout << "daval = " << dval << std::endl;

    return 0;
}
