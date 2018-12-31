#include <iostream>
#include <numeric>
#define REPEAT(X, S, E) for (int X = S; X < E; ++X)
const int N = 1 << (1 << ((1 << 1) + 1));
int n, a[N], s, cnt;
int main()
{
	freopen("cards.in", "r", stdin);
	freopen("cards.out", "w", stdout);
	std::cin >> n;
	REPEAT(i, 0, n)
		std::cin >> a[i];
	s = std::accumulate(a, a + n, 0);
	if (s % n)
		std::cout << -1 << std::endl;
	else if (n == 1)
		std::cout << 0 << std::endl;
	else
	{
		s /= n;
		REPEAT(i, 0, n - 1)
			if (a[i] - s)
				a[i + 1] += a[i] - s, a[i] = s, ++cnt;
		std::cout << cnt << std::endl;
	}
	return 0;
}