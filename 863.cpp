#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif
const int N = 1500;
int n, a, b, c, d, bit[N][N];
inline int LSB(int a)
{
	return a & (-a);
}
void addPoint(int c, int i, int z)
{
	for (; i <= n; i += LSB(i))
		bit[c][i] += z;
}
int query(int c, int i)
{
	int s = 0;
	for (; i; i -= LSB(i))
		s += bit[c][i];
	return s;
}
int main()
{
	//freopen("spiderman.in", "r", stdin);
	//freopen("spiderman.out", "w", stdout);
	scanf("%d", &n);
	for (std::string cmd; std::cin >> cmd;)
	{
		if (cmd == "QUERY")
		{
			std::cin >> a >> b >> c >> d;
			int s = 0;
			for (int i = a; i <= c; ++i)
				s += query(i, d) - query(i, b - 1);
			std::cout << s << ' ';
		}
		else
		{
			std::cin >> a >> b;
			addPoint(a, b, 1);
		}
	}
	return 0;
}