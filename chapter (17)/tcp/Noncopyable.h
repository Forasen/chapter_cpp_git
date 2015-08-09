/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef WD_NONCOPYABLE_H
#define WD_NONCOPYABLE_H

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &rhs);
	Noncopyable & operator=(const Noncopyable &rhs);
};


#endif

