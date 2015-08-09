/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include "Mylog.h"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <string>
#include <sstream>

namespace wd
{

Mylog * Mylog::pmylog_ = NULL;

Mylog & Mylog::createInstance()
{
	if(pmylog_ == NULL)
	{
		pmylog_ = new Mylog();
	}
	return *pmylog_;
}

void Mylog::destroy()
{
	if(pmylog_)
	{
		pmylog_->refCat_.info("destroy Mylog");
		log4cpp::Category::shutdown();
		delete pmylog_;
	}
}


Mylog::Mylog()
	: refCat_(log4cpp::Category::getRoot())
{
	log4cpp::PatternLayout *pPtnLy1 = 
		new log4cpp::PatternLayout();
	log4cpp::PatternLayout *pPtnLy2 = 
		new log4cpp::PatternLayout();
	pPtnLy1->setConversionPattern("%d:%p:%x:%m%n");
	pPtnLy2->setConversionPattern("%d:%p:%x:%m%n");

	log4cpp::OstreamAppender *pOsAppd = new 
		log4cpp::OstreamAppender("ostrem", &std::cout); 
	pOsAppd->setLayout(pPtnLy1);

	log4cpp::FileAppender *pFileAppd = new
		log4cpp::FileAppender("fileAppd", "./log.txt");
	pFileAppd->setLayout(pPtnLy2);

	refCat_.addAppender(pOsAppd);
	refCat_.addAppender(pFileAppd);
	refCat_.setPriority(log4cpp::Priority::DEBUG);

	refCat_.info("create Mylog");
}

void Mylog::error(const char *msg)
{
	refCat_.error(msg);
}

void Mylog::warn(const char *msg)
{
	refCat_.warn(msg);
}

void Mylog::info(const char *msg)
{
	refCat_.info(msg);
}

void Mylog::debug(const char *msg)
{
	refCat_.debug(msg);
}

void Mylog::setPriority(Priority priority)
{
	switch(priority)
	{
	case (ERROR):
		refCat_.setPriority(log4cpp::Priority::ERROR);
		break;
	case (WARN):
		refCat_.setPriority(log4cpp::Priority::WARN);
		break;
	case (INFO):
		refCat_.setPriority(log4cpp::Priority::INFO);
		break;
	case (DEBUG):
		refCat_.setPriority(log4cpp::Priority::DEBUG);
		break;
	default:
		refCat_.setPriority(log4cpp::Priority::DEBUG);
	}
}

const std::string int2string(int ival)
{
	std::ostringstream oss;
	oss << ival;
	return oss.str();
}

}
