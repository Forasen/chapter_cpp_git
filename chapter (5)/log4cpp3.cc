/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
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


	log4cpp::RollingFileAppender *pRollFileAppd =
		new log4cpp::RollingFileAppender("rollFileAppender",
				"second.log", 5 * 1024, 1);
	log4cpp::PatternLayout *pPtnLayout2 = new log4cpp::PatternLayout();
	pPtnLayout2->setConversionPattern("%d: %p %c %x: %m%n");
	pRollFileAppd->setLayout(pPtnLayout2);


	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(pFileAppd);
	root.addAppender(pRollFileAppd);
	root.setPriority(log4cpp::Priority::DEBUG);

	for(int idx = 0; idx != 100; ++idx)
	{
		std::string strError;
		std::ostringstream oss;
		oss << idx << ":Root Error Message!";
		strError = oss.str();
		root.error(strError);
	}

	log4cpp::Category::shutdown();

	return 0;
}
