#include <iostream>
#include <algorithm>
#include <numeric>
const int N = 500000;
int n, m, a[N], q[N], ans;
int main()
{
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = n; i < (n << 1); ++i)
		a[i] = a[i - n];
	std::partial_sum(a, a + (n << 1), a);
	ans = std::accumulate(a, a + m, 0);
	for (int f = m; f < 2 * n; ++f)
		if (a[f] - a[f - m] > ans)
			ans = a[f] - a[f - m];
	std::cout << ans << std::endl;
	return 0;
}