/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#define LOG4CPP 

#include "Mylog.h"
#include <string>
#include "func.h"

int main(void)
{
	LogError("Hello,world!");
	LogWarn("Hello,world!");
	LogInfo("Hello,world!");
	LogDebug("Hello,world!");

	func(3);

	LogDestroy();

    return 0;
}
