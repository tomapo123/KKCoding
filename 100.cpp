#include <iostream>
#include <string>
#include <algorithm>
int main()
{
	std::cout << "Enter 5 names:";
	std::string s[5];
	for (int i = 0; i < 5; ++i)
		std::getline(std::cin, s[i]);
	std::sort(s, s + 5);
	std::cout << "The names are:" << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << s[i] << std::endl;
}