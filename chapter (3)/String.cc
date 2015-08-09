/*********************************
 *@author  : NewYork
 *@email   : 2287794993@qq.com
**********************************/

class String
{
public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();

private:
	char *pStr_;
};

int main(void)
{
	String str1;
	String str2 = "Hello,world";
	String str3 = "wangdao";
	str2 = str3;
	std::cout << str1 << std::endl
			  << str2 << std::endl
			  << str3 << std::endl;
}
