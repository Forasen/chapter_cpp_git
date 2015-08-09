/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <math.h>

const double PI = 3.1415926;


class Figure
{
public:
	virtual float area()=0;
	virtual void displayName()=0;
};

class Circle : public Figure
{
public:
	Circle(float radius = 0)
		: fRadius_(radius)
	{}

	virtual float area()
	{
		return PI * fRadius_ * fRadius_;
	}

	virtual void displayName()
	{
		std::cout << "圆的面积：";
	}

private:
	float fRadius_;
};


class Rectangle : public Figure
{
public:
	Rectangle(float fx = 0, float fy = 0)
		: fx_(fx), fy_(fy)
	{}

	virtual float area()
	{
		return fx_ * fy_;
	}

	virtual void displayName()
	{
		std::cout << "矩形的面积：";
	}
private:
	float fx_;
	float fy_;
};

class Triangle : public Figure
{
public:
	Triangle(float fx = 0, float fy = 0, float fz = 0)
		: fx_(fx),
		  fy_(fy),
		  fz_(fz)
	{}

	virtual float area()
	{
		float p = (fx_ + fy_ + fz_) / 2;
		return sqrt(p * (p - fx_) * (p - fy_) * (p - fz_));
	}

	virtual void displayName()
	{
		std::cout << "三角形的面积：";
	}
private:
	float fx_;
	float fy_;
	float fz_;
};

int main(void)
{
	Figure * pFig = NULL;
	Circle c(3);
	Rectangle r(1.2f, 3.6f);
	Triangle t(3, 4, 5);

	pFig = &c;
	pFig->displayName();
	std::cout << pFig->area() << std::endl;
	pFig = &r;
	pFig->displayName();
	std::cout << pFig->area() << std::endl;
	pFig = &t;
	pFig->displayName();
	std::cout << pFig->area() << std::endl;
}
