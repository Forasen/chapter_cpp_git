/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include <NLPIR.h>
#include <stdio.h>

int main(void)
{
	if(!NLPIR_Init("../../", UTF8_CODE))
	{
		printf("init fails\n");
		return -1;
	}

	printf("Input sentence now!\n");
	NLPIR_FileProcess("../../test/C23Mine21.txt", "../../test/C23_res.txt", 0);
	NLPIR_Exit();

	return 0;
}

