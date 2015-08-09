/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <set>


class Student
{
public:
	Student(int id, const std::string & name)
		: id_(id),
		  name_(name)
	{}

friend std::ostream & operator<<(std::ostream &os, const Student &rhs);
friend bool operator<(const Student &lhs, const Student &rhs);

private:
	int id_;
	std::string name_;
};
std::ostream & operator<<(std::ostream &os, const Student &rhs)
{
	os << "id  : " << rhs.id_ << std::endl
	   << "name: " << rhs.name_;
	return os;
}

bool operator<(const Student &lhs, const Student &rhs)
{
	return lhs.name_ < rhs.name_;
}

int main(void)
{
	int arr[9] = {2, 1, 3 ,5, 4, 6, 3, 5, 6};
	std::multiset<int> int_set(arr, arr + 9);//set里面的元素是唯一的

	std::multiset<int>::iterator sit;
	for(sit = int_set.begin(); sit != int_set.end(); ++sit)
	{
		std::cout << *sit << " ";
	}
	std::cout << std::endl;

	return 0;
}
