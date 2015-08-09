/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>

class Computer
{
public:
	Computer(const char *name, float price)
		: fPrice_(price)
	{
		std::cout << "Computer(const char*, float)" << std::endl;
		pName_ = new char[strlen(name) + 1];
		strcpy(pName_, name);
		total_price_ += fPrice_;
	}

	~Computer()
	{
		std::cout << "~Computer()" << std::endl;
		if(pName_)
		{
			delete []pName_;
			pName_ = NULL;
		}

		total_price_ -= fPrice_;
	}

	static void print_total()
	{
		std::cout << "总价：" << total_price_ << std::endl;
	}

	static void print(Computer &com);
private:
	char *pName_;
	float fPrice_;
	static float total_price_;
};

float Computer::total_price_ = 0.0;

void Computer::print(Computer &com)
{
	std::cout << "名称：" << com.pName_ << std::endl;
	std::cout << "价格：" << com.fPrice_<< std::endl;
}


int main(void)
{
	Computer pc1("IBM", 7000);
	Computer::print(pc1);
	Computer::print_total();

	Computer pc2("ASUS", 4999);
	Computer::print(pc2);
	pc2.print_total();

	pc2.~Computer();
	pc2.print_total();

	return 0;
}
