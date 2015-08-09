/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <memory>
#include <stdio.h>

class Point {
public:
	Point()
		: ix_(0), iy_(0)
	{
		std::cout << "Point()" << std::endl;
	}
	Point(int ix, int iy)
		: ix_(ix), iy_(iy)
	{
		std::cout << "Point(int ix, int iy)" << std::endl;
	}
	
	~Point()
	{
		std::cout << "~Point() " << "ix_ = " << ix_ << ", iy_ = " << iy_ << std::endl;
	}


	void print()
	{
		std::cout << "(" << ix_
				  << "," << iy_ 
				  << ")" << std::endl;
	}


	int getx() const
	{
		return ix_;
	}

	int gety() const
	{
		return iy_;
	}


private:
	int ix_;
	int iy_;
};

class Point3D : public Point
{
public:
	Point3D(int ix, int iy, int iz)
		: Point(ix, iy), 
		  iz_(iz)
	{}

	void print3D()
	{
		std::cout << "(" << getx()
			      << "," << gety()
				  << "," << iz_
				  << ")" << std::endl;
	}

private:
	int iz_;
};


int main(void)
{
	Point p1(1, 1);
	p1.print();


	Point3D p2(2, 3, 4);
	p2.print3D();


	p1 = p2;
	p1.print();

	Point &refp1 = p2;
	refp1.print();

	Point *pp1 = &p2;
	pp1->print();

	std::cout << "Point3D's size = " << sizeof(p2) << std::endl;

}
