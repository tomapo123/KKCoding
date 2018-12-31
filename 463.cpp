#include <iostream>
const int Mod = 1e9 + 7;
int n;
int main()
{
	std::cin >> n;
	std::cout << ((((n + 2) % Mod) * ((n + 1) % Mod)) / 2) % Mod << std::endl;
}