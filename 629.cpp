#include <iostream>
#include <cstdio>
const unsigned long long N = 2e4;
unsigned long long n;
unsigned long long x[N];
int main()
{
	freopen("rib.in", "r", stdin);
	freopen("rib.out", "w", stdout);
	std::cin >> n;
	std::cout << (n <= 3 ? 0 : n * (n - 1)*(n - 2)*(n - 3) / 24);
	return 0;
}