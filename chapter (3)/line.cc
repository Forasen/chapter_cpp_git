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

class Line
{
public:
	Line(int x1, int y1, int x2, int y2)
		: pt1_(x1, y1),
		  pt2_(x2, y2) 
	{}

	Line(const Line & rhs)
		: pt1_(rhs.pt1_),
		  pt2_(rhs.pt2_)
	{
		std::cout << "Line(const Line & rhs)" << std::endl;
	}

	void draw()
	{
		pt1_.print();
		std::cout << "-->";
		pt2_.print();
	}
private:
	Point pt1_;
	Point pt2_;
};

int main(void)
{
	Line line1(1,2,3,4);
	line1.draw();
	Line line2(line1);
	line2.draw();

	return 0;
}
