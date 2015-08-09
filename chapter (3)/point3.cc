/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Point
{
public:
	Point(int ix, int iy, double &dz)
		: ix_(ix), 
		  iy_(iy), 
		  ref1(ix_), 
		  ref2(dz)
	{
		std::cout << "Point(int, int, double &)" << std::endl;
	}

	Point(const Point & rhs)
		: ix_(rhs.ix_),
		  iy_(rhs.iy_),
		  ref1(rhs.ref1),
		  ref2(rhs.ref2)
	{
		std::cout << "Point(const Point & rhs)" << std::endl;
	}

	void print()
	{
		std::cout << "(" << ix_
			      << "," << iy_
				  << "), (" << ref1
				  << "," << ref2 << ")" 
				  << std::endl;
	}

	void setx(int ix)
	{
		ix_ = ix;
	}
private:
	int ix_;
	int iy_;
	int &ref1;
	double &ref2;

};

int main(void)
{
	double dval = 5.0;
	Point pt1(3, 4, dval);
	pt1.print();

	std::cout << std::endl;
	Point pt2(pt1);
	pt2.print();

	std::cout << "改变pt1中的ix_" << std::endl;
	pt1.setx(7);
	pt1.print();
	pt2.print();
	
	std::cout << "改变dval的值" << std::endl;
	dval = 10.0;
	pt1.print();
	pt2.print();

	return 0;
}
