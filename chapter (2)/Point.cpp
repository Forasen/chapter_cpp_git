/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Point
{
public:
	explicit Point(int x = 0, int y = 0)
		: ix_(x), iy_(y)        
	{}

	void print()
	{
		std::cout << "(" << ix_ 
				  << ", " << iy_
				  << ")" << std::endl;
	}

	~Point()
	{
		std::cout << "Point::~Point()" << std::endl;
	
	}
private:
	int ix_;
	int iy_;
};

int main(void)
{
	Point pt1;
	pt1.print();

	{
		Point pt2(3, 4);
		pt2.print();
	}

	Point *ppt2 = new Point(5, 6);
	ppt2->print();
	delete ppt2;

	Point pt4 = Point();
	pt4.print();
	return 0;
}
