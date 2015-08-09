/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _WD_TASK_H
#define _WD_TASK_H

namespace wd
{

class Task
{
public:
	virtual ~Task(){}
	virtual void process()=0;
};

}//end of namespace wd

#endif
