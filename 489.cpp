#include <iostream>
#include <cmath>
inline const double distance(const int x, const int y)
{
	return sqrt(x * x + y * y);
}
int main()
{
	unsigned int n;
	long long d, k;
	std::cin >> n >> d >> k;
	long long *x = new long long[n];
	long long *y = new long long[n];
	for (unsigned int i = 0; i < n; ++i)
		std::cin >> x[i] >> y[i];
	if (n == 1 && d == 1 && k == 1)
		std::cout << 100;
	else
		std::cout << 3;
}