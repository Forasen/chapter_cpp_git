/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef __MY_POINT_H
#define __MY_POINT_H

class Line;

class Point
{
	friend class Line;
public:
	Point(int ix = 0, int iy = 0);

	void display();

private:
	int ix_;
	int iy_;
};

#endif
