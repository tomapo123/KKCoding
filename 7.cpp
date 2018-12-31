#include <iostream>
#include <cctype>
int main()
{
	for (char c; c != EOF; std::cout << c * (2 * islower(c = std::cin.get()) - 1)));
}
