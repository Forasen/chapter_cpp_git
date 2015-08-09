/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>

class X
{
public:
	X(int ival)
		: iy_(ival), ix_(iy_)
	{}

	void print()
	{
		std::cout << "ix_ = " << ix_
				  << ", iy_ = " << iy_
				  << std::endl;
	}
private:
	int ix_;
	int iy_;
};

int main(void)
{
	X x1(3);
	x1.print();
}
