#include <iostream>
#include <algorithm>
const int N = 1 << ((1 << ((1 << 1) + 1)) + 1);
int n, force[N][N], ans;
int main()
{
	freopen("sanguo.in", "r", stdin);
	freopen("sanguo.out", "w", stdout);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			std::cin >> force[i][j];
			force[j][i] = force[i][j];
		}
	for (int i = 1; i <= n; ++i)
	{
		std::sort(force[i] + 1, force[i] + n + 1);
		ans = std::max(ans, force[i][n - 1]);
	}
	std::cout << '1' << std::endl << ans << std::endl;
	return 0;
}