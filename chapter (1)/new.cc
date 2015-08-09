/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(void)
{
	int *pa = (int *)malloc(sizeof(int));
	*pa = 10;
	printf("*pa = %d\n", *pa);

	free(pa);


	int *pb = new int(5);
	std::cout << "*pb = " << *pb << std::endl;

	delete pb;

	int *pc = new int[10];
	for(int idx = 0; idx != 10; ++idx)
	{
		pc[idx] = idx;
		std::cout << "pc[" << idx << "] = " 
			      << pc[idx] << std::endl;
	}

	delete []pc;

	return 0;
}
