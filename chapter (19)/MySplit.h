/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#ifndef _MYSPLIT_H
#define _MYSPLIT_H

class MySplit
{
public:
	MySplit()
	{
		if(!NLPIR_Init("../../", UTF8_CODE))
		{
			printf("init fails\n");
			exit(EXIT_FAILURE);
		}
	}
	~MySplit()
	{
		NLPIR_Exit();
	}

	std::vector<std::string> wordSplit(std::string & txt)
	{
		std::vector<std::string> vec;
		const char *sResult;
		sResult = NLPIR_ParagraphProcess(txt.c_str(), 0);
		std::stringstream ss(sResult);
		std::string word;
		while(ss >> word)
		{
			vec.push_back(word);
		}

		return vec;
	}
};

class MyDict
{

private:
	std::map<std::string, int> dict_map_;
};


#endif
