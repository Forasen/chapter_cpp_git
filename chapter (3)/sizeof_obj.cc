/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Cell
{	
private:
	int a;     // 4
	char b;    // 1
	float c;   // 4
	double d;  // 8
	short e[5];// 10
	char &f;   // 8
	double &g; // 8
	static int h;
};

int main(void)
{
	std::cout << "sizeof(Cell) = " << sizeof(Cell) << std::endl;
}
