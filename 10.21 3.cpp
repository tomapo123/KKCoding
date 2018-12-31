#include <iostream>
#include <algorithm>
const long long N = 20000;
long long n, a[N];
long long work(long long i, long long j)
{
	if (i == j)
		return a[i];
	if (i + 1 == j)
		return std::max(a[i], a[j]);
	if (i + 2 == j)
		return std::max(a[i] + a[j], a[i + 1]);
	if (a[i] <= 0)
		return work(i + 1, j);
	if (a[j] <= 0)
		return work(i, j - 1);
	a[i + 1] -= a[i];
	a[j - 1] -= a[j];
	return work(i + 1, j - 1) + a[i] + a[j];
}
int main()
{
	std::cin >> n;
	for (long long i = 0; i < n; ++i)
		std::cin >> a[i];
	std::cout << work(0, n - 1) << std::endl;
	return 0;
}