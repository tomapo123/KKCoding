#include <iostream>
#include <algorithm>
#include <numeric>
const int N = 5000;
const int Infinity = 1e9;
bool calced[N];
int n, d[N], matrix[N][N];
inline int dist(int i, int j)
{
	return (i * 666 + j * j) % 233;
}
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
	for (int j = 1; j <= n; ++j)
		for (int i = 1; i <= n; ++i)
			if (i != j)
				matrix[j][i] = dist(i, j);
	Dijkstra();
	std::cout << std::accumulate(d + 1, d + n + 1, 0) << std::endl;
	//\
	return 0;
}