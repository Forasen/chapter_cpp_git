/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <string>

class MetaData
{
public:
	MetaData(int size, const std::string &name)
		: name_(name),
		  size_(size)
	{}

	MetaData(const MetaData &other)
		: name_(other.name_),
		  size_(other.size_)
	{
		std::cout << "MetaData(const MetaData &)" << std::endl;
	}

	MetaData(MetaData &&other)
		: name_(std::move(other.name_)),
		  size_(other.size_)
	{
		std::cout << "MetaData(MetaData &&other)" << std::endl;
	}

	std::string getName()const
	{	return name_;	}

	int getSize() const
	{	return size_;	}

private:
	std::string name_;
	int size_;
};

class ArrayWrapper
{
public:
	ArrayWrapper()
		: pVals_(new int[64]),
		  metadata_(64, "ArrayWrapper")
	{
		std::cout << "ArrayWrapper()" << std::endl;
	}

	ArrayWrapper(int n)
		: pVals_(new int[n]),
		  metadata_(n, "ArrayWrapper")
	{
		std::cout << "ArrayWrapper(int n)" << std::endl;
	}

	ArrayWrapper(const ArrayWrapper &other)
		: pVals_(new int[other.metadata_.getSize()]),
		  metadata_(other.metadata_)
	{
		std::cout << "ArrayWrapper(const ArrayWrapper&)" << std::endl;

		for(int idx = 0; idx != other.metadata_.getSize(); ++idx)
		{
			pVals_[idx] = other.pVals_[idx];
		}
	}

	ArrayWrapper(ArrayWrapper &&other)
		: pVals_(other.pVals_),
		  metadata_(std::move(other.metadata_))
	{
		std::cout << "ArrayWrapper(ArrayWrapper &&other)" << std::endl;
		other.pVals_ = NULL;
	}

	~ArrayWrapper()
	{
		delete [] pVals_;
		std::cout << "~ArrayWrapper()" << std::endl;
	}

private:
	int *pVals_;
	MetaData metadata_;
};


int main(void)
{
	ArrayWrapper aw1;
	std::cout << "移动构造函数" << std::endl;
	ArrayWrapper aw2(std::move(aw1));

}
