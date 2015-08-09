/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Point
{
public:
	Point(): ix_(0), iy_(0){}

	Point(int ix, int iy) : ix_(ix), iy_(iy){}

	void display()
	{
		std::cout << "(" << ix_
				  << "," << iy_
				  << ")" << std::endl;
	}

	int getx()const
	{
		return ix_;
	}

	int gety() const
	{
		return iy_;
	}

private:
	int ix_;

protected:
	int iy_;
};


class Point3D : public Point
{
public:
	Point3D(int ix, int iy, int iz)
		: Point(ix, iy), iz_(iz)
	{}

	void display()
	{
		std::cout << "(" << getx()
			      << "," << gety()
				  << "," << iz_
				  << ")" << std::endl;
	}

	int calcSum()
	{
		return getx() + iy_ + iz_;
	}
private:
	int iz_;
};

int main(void)
{
	Point p1(7, 8);
	p1.display();

	Point3D p2(3, 4, 5);
	p2.display();

	int ret = p2.calcSum();
	std::cout << "sum = " << ret << std::endl;

	std::cout << "ix_ = " << p2.getx() << std::endl;

	return 0;
}
