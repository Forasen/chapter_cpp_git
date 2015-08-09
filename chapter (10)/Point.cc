/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: ix_(ix), iy_(iy)
	{
		std::cout << "Point(int ix, int iy)" << std::endl;
	}

	Point(const Point &rhs)
		: ix_(rhs.ix_),
		  iy_(rhs.iy_)
	{
		std::cout << "Point(const Point &rhs)" << std::endl;
	}
	
	~Point()
	{
		std::cout << "~Point()" << std::endl;
	}

private:
	int ix_;
	int iy_;
};

Point getPoint()
{
	{
	Point tmp;//RVO ,tmp是一个临时对象
	return tmp;
	}
}


int main(void)
{
	Point p1 = getPoint();

	return 0;
}
