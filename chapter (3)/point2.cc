/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Point
{
public:
	Point(int ix, int iy)
		: ix_(ix), iy_(iy) 
	{
	}

	Point(const Point & rhs)
		: ix_(rhs.ix_),
		  iy_(rhs.iy_)
	{
	}

	void print()
	{
		std::cout << "(" << ix_
			      << "," << iy_
				  << ")" << std::endl;
	}
private:
	const int ix_;
	const int iy_;

};

int main(void)
{
	Point pt1(3, 4);
	pt1.print();

	Point pt2 = pt1;
	pt2.print();
	return 0;
}
