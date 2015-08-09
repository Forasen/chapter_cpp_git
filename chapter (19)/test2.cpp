/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include "NLPIR.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char sSentence[2000];
	const char *sResult;
	if(!NLPIR_Init("../../", UTF8_CODE))
	{
		printf("Init fails\n");
		return -1;
	}

	printf("Input sentence now('q' to quit)!\n");
	scanf("%s", sSentence);
	while(strcmp(sSentence, "q") != 0)
	{
		sResult = NLPIR_ParagraphProcess(sSentence, 1);
		printf("%s\nInput string now('q' to quit)!\n", sResult);
		scanf("%s", sSentence);
	}

	memset(sSentence, 0, sizeof(sSentence));
	const char *pstr = "我是中国人";
	printf("%d\n", sizeof(pstr));
	sResult = NLPIR_ParagraphProcess(pstr, 0);

	//std::stringstream (sResult);
	
	printf("%s\n", sResult);

	NLPIR_Exit();
	return 0;
}
