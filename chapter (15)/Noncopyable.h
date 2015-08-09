/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_NONCOPYABLE_H
#define _WD_NONCOPYABLE_H

namespace wd
{

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}

private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable &operator=(const Noncopyable & rhs);
};
}//end of namespace wd

#endif
