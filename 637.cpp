#include <iostream>
#include <algorithm>
const int N = 1000;
const int Infinity = 1e9;
int n;
bool calced[N];
int matrix[N][N], d[N];
void Dijkstra()
{
	std::fill(d + 2, d + n + 2, Infinity);
	for (int i = 1; i <= n; ++i)
	{
		int u = n + 1;
		for (int v = 1; v <= n; ++v)
			if (!calced[v] && d[v] < d[u])
				u = v;
		calced[u] = true;
		for (int v = 1; v <= n; ++v)
			d[v] = std::min(d[v], d[u] + matrix[u][v]);
	}
}
int main()
{
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			std::cin >> matrix[i][j];
			if (!(matrix[i][j] + 1))
				matrix[i][j] = Infinity;
		}
	Dijkstra();
	for (int i = 1; i <= n; ++i)
		std::cout << (d[i] >= Infinity ? -1 : d[i]) << ' ';
	return 0;
}