/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

int main(void)
{
	log4cpp::FileAppender *pFileAppd = 
		new log4cpp::FileAppender("fileAppender", "first.log");
	log4cpp::PatternLayout *pPtnLayout = new log4cpp::PatternLayout();
	pPtnLayout->setConversionPattern("%d: %p %c %x: %m%n");
	pFileAppd->setLayout(pPtnLayout);


	log4cpp::PatternLayout *pPtnLayout2 = new log4cpp::PatternLayout();
	pPtnLayout2->setConversionPattern("%d: %p %c %x: %m%n");
	log4cpp::OstreamAppender *pOsAppd = 
		new log4cpp::OstreamAppender("osAppender", &std::cout);
	pOsAppd->setLayout(pPtnLayout2);

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(pFileAppd);
	root.addAppender(pOsAppd);
	root.setPriority(log4cpp::Priority::DEBUG);

	root.error("Message error!");
	root.info("Program info which can be writtern");
	root.debug("Message debug!");
	root.warn("Message warn!");
	root.fatal("Message fatal!");

	log4cpp::Category::shutdown();

	std::cout << "" << std::endl;

	return 0;
}
