/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include "nested.h"

class Line::Pimpl
{
private:
	class Point
	{
	public:
		Point(int ix = 0, int iy = 0)
			: ix_(ix), iy_(iy)
		{}

		void printpoint();

	private:
		int ix_;
		int iy_;
	};

public:
	Pimpl(int x1, int y1, int x2, int y2)
		: p1_(x1, y1), p2_(x2, y2)
	{}

	void printline()
	{
		p1_.printpoint();
		std::cout << "  --->";
		p2_.printpoint();
	}

private:
	Point p1_;
	Point p2_;
};
		
void Line::Pimpl::Point::printpoint()
{
	std::cout << "(" << ix_
			  << "," << iy_
			  << ")" <<std::endl;
}

Line::Line(int x1, int y1, int x2, int y2)
{	
	pImpl_ = new Line::Pimpl(x1, y1, x2, y2);
}

void Line::printline()
{
	pImpl_->printline();
}


int main(void)
{
	Line line1(1, 2, 3, 4);
	line1.printline();

    return 0;
}
