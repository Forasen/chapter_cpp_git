/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/
#include <iostream>

class Data
{
public:
	int getlen()
	{	return 5;	}
};

class DataPtr
{
public:
	DataPtr()
		: pData_(new Data)
	{
		
	}

	~DataPtr()
	{
		delete pData_;
	}

	Data * operator->()
	{
		return pData_;
	}

private:
	Data *pData_;
};

int main(void)
{
	DataPtr dp;
	std::cout << "Data's len = " << dp->getlen() << std::endl;
	std::cout << (dp.operator->())->getlen() << std::endl;

	return 0;
}
