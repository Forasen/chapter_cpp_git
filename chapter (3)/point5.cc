/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class Point
{
public:
	Point(int ix = 0, int iy = 0)
		: ix_(ix),
		  iy_(iy)
	{
		static int iCount = 0;
		++iCount;
		std::cout << iCount << "次调用构造函数" << std::endl;
	}

	void print() const
	{
		std::cout << "(" << ix_
				  << "," << iy_
				  << ")" << std::endl;
	}

private:
	int ix_;
	int iy_;
};

int main(void)
{
	Point pt1[2];
	
	Point pt2[2] = {Point(1, 2), Point(3, 4)};
	pt2[0].print();
	pt2[1].print();

	Point pt3[] = {Point(5, 6), Point(7, 8)};

	Point pt4[5] = {Point(9, 10), Point(11, 12)};
	
}
