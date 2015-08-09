/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Point
{
public:
	Point(int ix =0, int iy = 0)
		: ix_(ix),
		  iy_(iy)
	{}

	void print() const
	{
		std::cout << "(" << ix_
				  << "," << iy_
				  << ")" << std::endl;

		set();
	}

private:
	void set() const 
	{
		std::cout << "set()" << std::endl;
	}

private:
	int ix_;
	int iy_;
};

int main(void)
{
	Point pt1(3, 4);
	pt1.print();

	const int a = 10;
	const Point pt2(5, 6);
	pt2.print();

	return 0;
}
