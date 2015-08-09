/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

int main(void)
{
	log4cpp::OstreamAppender *
		pOsAppender = new log4cpp::OstreamAppender("cout", &std::cout);
	pOsAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(pOsAppender);
	root.setPriority(log4cpp::Priority::ERROR);

	root.error("Hello log4cpp in error Message!");
	root.warn("Hello log4cpp in warn Message!");
	root.debug("Hello log4cpp in debug Message!");
	root.info("Hello log4cpp in info Message!");

	log4cpp::Category::shutdown();
}
