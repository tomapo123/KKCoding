#include <iostream>
const unsigned long long N = 1 << (1 << (1 << 1) + 1);
const unsigned long long M = 1 << (1 << (1 << 1) + 1);
const unsigned long long Mod = 1000007;
unsigned long long n, m, a[N], f[N][M];
int main()
{
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	std::cin >> n >> m;
	for (unsigned long long i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (unsigned long long i = 0; i <= n; ++i)
		f[i][0] = 1;
	for (unsigned long long i = 1; i <= n; ++i)
		for (unsigned long long j = 1; j <= m; ++j)
			f[i][j] = (f[i - 1][j] + f[i][j - 1] - (j - 1 >= a[i] ? f[i - 1][j - 1 - a[i]] : 0));
	std::cout << f[n][m] % Mod << std::endl;
	return 0;
}