/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

#include <iostream>
#include <memory>

class Child;
class Parent;

typedef std::shared_ptr<Child> Child_ptr;
typedef std::shared_ptr<Parent> Parent_ptr;


class Child
{
public:
	Child()
	{
		std::cout << "Child()" << std::endl;
	}

	~Child()
	{
		std::cout << "~Child()" << std::endl;
	}

	Parent_ptr parent_;//shared_ptr
};


class Parent
{
public:
	Parent()
	{
		std::cout << "Parent()" << std::endl;
	}

	~Parent()
	{
		std::cout << "~Parent()" << std::endl;
	}

	Child_ptr child_;
};



int main(void)
{
	{

	Parent_ptr parent(new Parent);
	Child_ptr child(new Child);

	std::cout << "parent's count = " << parent.use_count() << std::endl;
	std::cout << "child's count  = " << child.use_count() << std::endl;
	
	std::cout << "进行复制之后：" << std::endl;
	parent->child_ = child;
	std::cout << "child's count  = " << child.use_count() << std::endl;

	child->parent_ = parent;
	std::cout << "parent's count = " << parent.use_count() << std::endl;
	}

	
	return 0;

}
