/*
#include <iostream>
#include <cstdio>
int k, n;
int main()
{
	//freopen("usatour.in", "r", stdin);
	//freopen("usatour.out", "w", stdout);
	std::cin >> k >> n;
	if (n % 3)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	n /= 3;

}
*/
#include <iostream>
#include <algorithm>
void init_array(unsigned long long m, unsigned long long n);
const unsigned long N = 500;//范围
const unsigned long M = 100;//范围
unsigned long long f[N][M];//定义数组
int main()
{
	unsigned long long n, m;
	std::cin >> m >> n;//程序输入
	unsigned long s = 0;
	for (unsigned long long k = 0; k <= m - 1; k++)
	{
		m -= k;
		init_array(m + k, n);
		for (unsigned long long i = 2; i <= n; i++)
			for (unsigned long long j = 1; j <= std::min(i, m); j++)
				f[i][j] = f[i - 1][j - 1] + f[i - j][j];
		s += f[n][m];
		m += k;
	}
	std::cout << s << std::endl;
	return 0;
}
void init_array(unsigned long long m, unsigned long long n)
{
	for (unsigned long long i = 0; i < n; i++)
		for (unsigned long long j = 0; j < m; j++)
			f[i][j] = 0;
	f[1][1] = 1;
}
