/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include "Point.h"
#include <iostream>
#include <math.h>

Point::Point(int ix, int iy)
	: ix_(ix), iy_(iy)
{}

void Point::display()
{
	std::cout << "(" << ix_
		      << "," << iy_
			  << ")" << std::endl;
}

class Line
{
public:
	float distance(Point &p1, Point &p2)
	{
		float d = sqrt(
				(p1.ix_ - p2.ix_) * (p1.ix_ - p2.ix_) + 
				(p1.iy_ - p2.iy_) * (p1.iy_ - p2.iy_)
				);

		return d;
	}

	void setPoint(Point &pt, int x, int y)
	{
		pt.ix_ = x;
		pt.iy_ = y;
	}

private:
	int ival;
};

int main(void)
{
	Point p1(1, 2), p2(4, 5);
	p1.display();
	p2.display();
	std::cout << "p1与p2的距离:";
	Line line2;
	std::cout << line2.distance(p1, p2) << std::endl;

	line2.setPoint(p1, 7, 8);
	std::cout << "p1的值：";
	p1.display();
}
