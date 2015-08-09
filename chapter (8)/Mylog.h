/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _MYLOG_H
#define _MYLOG_H

#include <log4cpp/Category.hh>

namespace wd
{

enum Priority
{
	ERROR = 0,
	WARN,
	INFO,
	DEBUG
};

class Mylog
{
public:
	static Mylog & createInstance();
	static void destroy();

	void error(const char *msg);
	void warn(const char *msg);
	void info(const char *msg);
	void debug(const char *msg);

	void setPriority(Priority priority);
private:
	Mylog();

private:
	static Mylog *pmylog_;
	log4cpp::Category &refCat_;
};

const std::string int2string(int ival);

#define postfix(fmt)	std::string(fmt).append("[").append(__FILE__)\
		.append(":").append(__func__).append(":")\
		.append(wd::int2string(__LINE__)).append("]").c_str()


}

#ifdef LOG4CPP
wd::Mylog &log = wd::Mylog::createInstance();
#else
extern wd::Mylog &log;
#endif

#define LogError(msg)  log.error(postfix(msg))
#define LogWarn(msg)   log.warn(postfix(msg))
#define LogInfo(msg)   log.info(postfix(msg))
#define LogDebug(msg)  log.debug(postfix(msg))
#define LogDestroy()   log.destroy()

#endif 
