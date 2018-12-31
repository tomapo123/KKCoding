#include <iostream>
#include <algorithm>
const long long N = 5e5;
long long k, n, a[N], cnt;
int main()
{
	freopen("friendship.in", "r", stdin);
	freopen("friendship.out", "w", stdout);
	std::cin >> k >> n;
	for (long long i = 0; i < n; ++i)
		std::cin >> a[i];
	std::sort(a, a + n);
	for (long long i = 0; i < n; ++i)
		cnt += (std::upper_bound(a, a + n, a[i] + k) - std::lower_bound(a, a + n, a[i] - k) - 1);
	std::cout << cnt / 2 << std::endl;
	return 0;
}