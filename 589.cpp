#include <iostream>
#include <algorithm>
const int N = 10000;
const int M = 10000;
const int Infinity = 1e9;
int n, m, x[N], d[N];
struct
{
	int a, b, w;
} e[M << 1];
void BellmanFord()
{
	int t;
	std::fill(d + 2, d + n + 1, Infinity);
	for (int k = 1; k < n; ++k)
		for (int i = 0; i < m; ++i)
		{
			d[e[i].b] = std::min(d[e[i].a] + e[i].w, d[e[i].b]);
		}
}
int main()
{
	int a, b, c;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> x[i];
	std::cin >> m;
	for (int i = 0; i < m; ++i)
	{
		std::cin >> a >> b >> c;
		e[i].a = e[i + m].b = a;
		e[i].b = e[i + m].a = b;
		e[i].w = e[i + m].w = c;
	}
	m <<= 1;
	BellmanFord();
	unsigned long long s = 0;
	for (int i = 1; i <= n; ++i)
		if (d[i] != Infinity)
			s += d[i] * x[i];
	std::cout << s << std::endl;
	return 0;
}