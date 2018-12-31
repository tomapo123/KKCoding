#include <iostream>
#include <algorithm>
const int N = 5000;
const int M = 500;
int n, m, a[N], f[N][M];
char t;
int main()
{
	//freopen
	std::cin >> n >> m;
	for (int i = 1; i <= n; a[i++] = t == 'B')
		std::cin >> t;
	for (int i = 1; i <= n; ++i)
		f[i][0] = f[i - 1][0] + (a[i] == a[0]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			f[i][j] = (a[i] == a[i - 1] ? f[i - 1][j] + 1 : std::max(f[i - 1][j - 1] + 1, f[i - 1][j]));
	std::cout << *std::max_element(f[n], f[n] + m + 1) << std::endl;
	return 0;
}