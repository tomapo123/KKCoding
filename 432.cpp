#include <iostream>
#include <ctime>
inline double max(const double a, const double b)
{
	return a > b ? a : b;
}
int main()
{
	time_t start = time(static_cast<time_t *const>(0));
	size_t n;
	unsigned int m;
	std::cin >> n >> m;
	unsigned long long *h = new unsigned long long[n], t;
	for (size_t i = 0; i < n; ++i)
	{
		std::cin >> t;
		h[i] = t + (i == 0 ? 0 : h[i - 1]);
	}
	double avg = 0;
	for (size_t rm = m; rm <= n && (time(static_cast<time_t *const>(0)) - start > static_cast<time_t>(2)); ++rm)
		for (size_t i = 0; i <= n - rm; ++i)
			avg = max(avg, (h[i + rm - 1] - (i >= 1 ? h[i - 1] : 0)) / static_cast<double>(rm));
	std::cout << static_cast<unsigned long long>(avg * 1000) << std::endl;
}