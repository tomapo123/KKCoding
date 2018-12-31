#include <iostream>
unsigned long long qpowmod(unsigned long long x, unsigned long long p, unsigned long long m)
{
	if (!p)
		return 1;
	unsigned long long q = qpowmod(x, p / 2, m);
	return (q * q * (p & 1 ? x : 1) % m);
}
int main()
{
	unsigned long long x, m, p;
	std::cin >> x >> p >> m;
	x %= m;
	if (!x)
		std::cout << 0 << std::endl;
	else if (!(x + 1 - m))
		std::cout << (p & 1 ? -1 : 1) << std::endl;
	else if (!(x - 1))
		std::cout << 1 << std::endl;
	else
		std::cout << qpowmod(x, p, m) << std::endl;
	return 0;
}