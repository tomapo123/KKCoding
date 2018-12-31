#include <iostream>
#include <algorithm>
const int N = 2e4;
const int M = 5e4;
int n, m, x[M], A[M], B[M], C[M], D[M];
void CountingSort(int *a, int n, int k)
{
	int i, b[M], c[N];
	for (i = 0; i <= k; ++i)
		c[i] = 0;
	for (i = 0; i < n; ++i)
		c[a[i]]++;
	for (i = 0; i <= k; ++i)
		c[i] += c[i - 1];
	for (int j = n - 1; j + 1; --j)
	{
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
	for (int i = 0; i < n; ++i)
		a[i] = b[i];
}
int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i)
		std::cin >> x[i];
	CountingSort(x, m, *std::max_element(x, x + m));
	for (int u = 2; u <= (x[m - 3] - x[0]); u += 2)
	{
		int v = u / 2;
		for (int w = u * 3 + 1; w <= (x[m - 2] - x[1]); ++w)
			for (int t = x[0]; t <= (x[m - 1] - u - v - w); t = *((&t) + 1))
				if (std::binary_search(x, x + m, t + u) && std::binary_search(x, x + m, t + u + v) && std::binary_search(x, x + m, t + u + v + w))
					++A[t], ++B[t + u], ++C[t + u + v], ++D[t + u + v + w];
	}
	for (int i = 0; i < m; ++i, std::cout << std::endl)
		std::cout << A[i] << ' ' << B[i] << ' ' << C[i] << ' ' << D[i];
	return 0;
}