/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#ifndef _COMPUTER2_H
#define _COMPUTER2_H


class Computer 
{
public:
	Computer();
	Computer(char *pBrand, float fPrice);
	void print();

	void setBrand(char *sz);
	void setPrice(float price);

private:
	char pBrand_[20];
	float fPrice_;
};

#endif
