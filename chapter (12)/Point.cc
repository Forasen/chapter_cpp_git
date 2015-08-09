/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <memory>
#include <stdio.h>

class Point : public std::enable_shared_from_this<Point>
{
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

	Point(const Point &rhs)
		: ix_(rhs.ix_),
		  iy_(rhs.iy_)
	{
		std::cout << "Point(const Point &rhs)" << std::endl;
	}
	
	~Point()
	{
		std::cout << "~Point() " << "ix_ = " << ix_ << ", iy_ = " << iy_ << std::endl;
	}

	std::shared_ptr<Point> add(const Point * rhs)
	{
		ix_ += rhs->ix_;
		iy_ += rhs->iy_;
		return shared_from_this();
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
	Point tmp;
	return tmp;
}


int test(void)
{

	Point *pt = new Point(1,2);

	std::shared_ptr<Point> p1(pt);
	std::shared_ptr<Point> p2(pt);
	std::cout << "p1's use_count() = " << p1.use_count() << std::endl;

	return 0;
}

void fcloser(FILE * pf)
{
	if(pf)
	{
		std::cout << "fcloseer()" << std::endl;
		fclose(pf);
	}
}


struct fpcloser
{
	void operator()(FILE *fp)
	{
		if(fp)
		{
			std::cout << "fpcloser()" << std::endl;
			fclose(fp);
		}
	}
};

int main(void)
{
	std::shared_ptr<Point> p1(new Point(1, 2));
	std::shared_ptr<Point> p2(new Point(3, 4));

	std::shared_ptr<Point> p3 = p1->add(p2.get());
	p2.swap(p3);

	FILE* pf = fopen("Point3D.cc", "r+");

	std::shared_ptr<FILE> p4(pf, fpcloser());

	return 0;
}
