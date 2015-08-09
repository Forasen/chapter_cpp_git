/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable & operator=(const Noncopyable & rhs);
};

#endif
