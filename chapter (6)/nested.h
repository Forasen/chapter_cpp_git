/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _MY_NESTED_H
#define _MY_NESTED_H
class Line
{
	class Pimpl;
public:
	Line(int x1, int y1, int x2, int y2);
	void printline();

private:
	Pimpl *pImpl_;
};

#endif
