#include <iostream>
const int N = 5000;
int n, m, k, a[N], x[N], q[N], f[N][N];
int main()
{
	std::cin >> n >> m >> k;
	if (n >= m * k)
	{
		f[n + 1][m] = -1;
		goto end;
	}
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int j = 1; j <= m; ++j)
	{
		int l = 0, r = 0;
		for (int i = 0; i <= n + 1 && i <= j * k; ++i)
		{
			while (l < r && i - q[l] >= k)
				++l;
			while (l < r && f[i][j - 1] > f[q[r - 1]][j - 1])
				--r;
			q[r++] = i;
			x[i] = f[q[l]][j - 1];
		}
		for (int i = 1; i <= n + 1 && i <= j * k; ++i)
			f[i][j] = x[i - 1] + a[i];
	}
end:
	std::cout << f[n + 1][m] << std::endl;
	return 0;
}