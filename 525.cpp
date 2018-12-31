#include <iostream>
int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << (a / double(b) >= 0.6 ? "Pass" : "Fail");
}