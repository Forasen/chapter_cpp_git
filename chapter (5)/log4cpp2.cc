/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <stdio.h>

int main(void)
{
	log4cpp::OstreamAppender * pOstreamAppender = 
		new log4cpp::OstreamAppender("std::cout", &std::cout);
	log4cpp::PatternLayout *pPtnLayout = new log4cpp::PatternLayout();
	pPtnLayout->setConversionPattern("%d:%p %c %x: %m%n");
	pOstreamAppender->setLayout(pPtnLayout);

	log4cpp::Category & root = log4cpp::Category::getRoot();

	log4cpp::Category & infoCategory = root.getInstance("infoCategory");
	infoCategory.addAppender(pOstreamAppender);
	infoCategory.setPriority(log4cpp::Priority::DEBUG);

	infoCategory.info("sytem is running!");
	infoCategory.warn("system has a warning!");
	infoCategory.error("system has a error, can't find a file");
	infoCategory.fatal("system has a fatal error, must be shutdown");
	infoCategory.info("system shutdown, you can find some information in a system log");
	
	log4cpp::Category::shutdown();

	printf("hello,world!-- [%s:%s-%d]\n", __FILE__, __func__, __LINE__); 
	return 0;

}

