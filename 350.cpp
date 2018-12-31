#include "stdafx.h"
#include <iostream>
#define M 35
#define N 20005
using namespace std;
int n, m, w[M], v[M], f[2][N], c, p1, p2, z;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> w[i] >> v[i];
	cin >> p1 >> p2 >> z;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= n; j++)
		{
			if (i != p1 and i != p2 and j >= w[i])
				f[i & 1][j] = max(f[i & 1 ^ 1][j], f[i & 1 ^ 1][j - w[i]] + v[i]);
			else f[i & 1][j] = f[i & 1 ^ 1][j];
		}
	c = f[m & 1][n];
	if (n >= w[p1] + w[p2])
		c = max(c, f[m & 1][n - w[p1] - w[p2]] + v[p1] + v[p2] + z);
	if (n >= w[p1])
		c = max(c, f[m & 1][n - w[p1]] + v[p1]);
	if (n >= w[p2])c = max(c, f[m & 1][n - w[p2]] + v[p2]);
	cout << c;
	return 0;
}