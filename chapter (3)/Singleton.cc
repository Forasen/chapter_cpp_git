/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include <stdio.h>
#include <iostream>

class Singleton
{

public:
	static Singleton *createInstance()
	{
		if(pInstance == NULL)
		{
			pInstance = new Singleton();
		}
		return pInstance;
	}
private:
	Singleton(){}

private:
	static Singleton * pInstance;
};

Singleton * Singleton::pInstance = NULL;

int main(void)
{
	Singleton *p1 = Singleton::createInstance();
	Singleton *p2 = Singleton::createInstance();
	Singleton *p3 = Singleton::createInstance();

	printf("p1 = %x\n", p1);
	printf("p2 = %x\n", p2);
	printf("p3 = %x\n", p3);
	
}
