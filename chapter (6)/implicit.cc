/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class AnotherPoint
{
	friend class Point;
public:
	AnotherPoint(double dx = 1, double dy = 1)
		: dx_(dx), dy_(dy)
	{}

	friend std::ostream & operator<<(std::ostream &os, const AnotherPoint &rhs);


private:
	double dx_;
	double dy_;
};

std::ostream & operator<<(std::ostream &os, const AnotherPoint &rhs)
{
	os << "(" << rhs.dx_ << "," << rhs.dy_ << ")";
	return os;
}

class Point
{
public:
	Point (int ix = 0, int iy = 0)
		: ix_(ix), iy_(iy)
	{
		std::cout << "Point(int,int)" << std::endl;
	}

	Point(AnotherPoint &rhs)
		: ix_(rhs.dx_),
		  iy_(rhs.dy_)
	{}

	friend std::ostream & operator<<(std::ostream &os, const Point &rhs);

private:
	int ix_;
	int iy_;
};

std::ostream & operator<<(std::ostream &os, const Point &rhs)
{
	os << "(" << rhs.ix_ << "," << rhs.iy_ << ")";
}


int main(void)
{
	Point p1;
	std::cout << "5 转换成";
	p1 = 5;
	std::cout << p1 << std::endl;

	double dval = 6.6;
	p1 = dval;
	std::cout << "6.6 转换成";
	std::cout << p1 << std::endl;

	AnotherPoint p2(12.34, 56.78);
	std::cout << "(12.34, 56.78)转换成";
	p1 = p2;
	std::cout << p1 << std::endl;

    return 0;
}
