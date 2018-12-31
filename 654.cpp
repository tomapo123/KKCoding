#include <iostream>
#include <numeric>
const unsigned long long N = 1e6;
unsigned long long n, m, s[N], sum;
bool OK(unsigned long long k)
{
	unsigned long long num = 0;
	for (unsigned long long i = 0; i < n; ++i)
		num += s[i] / k;
	return num >= m;
}
int main()
{
	std::cin >> n >> m;
	for (unsigned long long i = 0; i < n; ++i)
	{
		std::cin >> s[i];
		sum += s[i];
	}
	if (sum < m)
		std::cout << "Failed" << std::endl;
	else if (sum == m)
		std::cout << 1 << std::endl;
	else
	{
		unsigned long long l = 1, r = sum / m, k, a = 1;
		while (l <= r)
		{
			k = l + ((r - l) >> 1);
			if (OK(k))
				a = k, l = k + 1;
			else
				r = k - 1;
		}
		std::cout << a << std::endl;
	}
	return 0;
}