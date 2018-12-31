#include <iostream>
int main()
{
	int k, i = 1;
	std::cin >> k;
	double s = 1;
	while (s <= k)
		s += 1.0 / (++i);
	std::cout << i + 1 << std::endl;
}