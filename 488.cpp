#include <iostream>
#include <string>
const std::string pow(const std::string &a, const int &b);
const std::string operator*(const std::string &a, const std::string &b);
int main()
{
	int n;
	std::cin >> n;
	std::cout << pow(std::string("2"), n - 1) << std::endl;
	return 0;
}
const std::string pow(const std::string &a, const std::string &b)
{
	std::string ret = "1";
	for (int i = 0; i < b; ++i)
		ret = ret * a;
	return ret;
}
const std::string operator*(const std::string &a, const std::string &b)
{

}