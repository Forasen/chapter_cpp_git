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
		std::cout << "Point()" << std::endl;
	}
	Point(const Point & rhs)
		: ix_(rhs.ix_),
		  iy_(rhs.iy_)
	{
		std::cout << "Point(const Point &rhs)" << std::endl;
	}

	Point & operator=(const Point & rhs)
	{
		std::cout << "Point & operator=(const Point&rhs)" 
				  << std::endl;
		if(this == &rhs)
			return *this;
		ix_ = rhs.ix_;
		iy_ = rhs.iy_;

		return *this;
	}

	void print()
	{
		std::cout << "(" << ix_
				  << "," << iy_
				  << ")" << std::endl;
	}
private:
	int ix_;
	int iy_;
};

Point getPoint()
{
	return Point(5, 6);
	//Point pt1(5, 6);
	//return pt1;
}

int main(void)
{
	Point pt1(3, 4);
	pt1.print();

	Point pt2 = pt1;
	pt2.print();

	Point pt3 = getPoint();
	pt3.print();

	return 0;
}
