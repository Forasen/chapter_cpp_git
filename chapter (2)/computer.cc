/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string.h>

class Computer   
{
	char pBrand_[20];
	float fPrice_;

public:
	void print()
	{
		std::cout << "品牌：" << pBrand_ << std::endl;
		std::cout << "价格：" << fPrice_ << std::endl;
	}
	void setBrand(char *pstr)
	{
		strcpy(pBrand_, pstr);
	}

	void setPrice(float price) {
		fPrice_ = price;
	}
};


struct Student
{
	char stu_name__[100];
	int stu_no_;
};

int main(void)
{
	Computer pc1;

	Computer pc2;
	pc2.setPrice(5000);
	pc2.setBrand("Lenovo");
	pc2.print();


	Student s1;
	s1.stu_no_ = 100;
	return 0;
}
