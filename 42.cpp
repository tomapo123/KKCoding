#include <iostream>
const int N = 100;
int n, k, x[N], ans;
bool vst[N];
unsigned long long f[21] = { 1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000 };
bool isPrime(int x)
{
	for (int i = 2; i * i <= x; ++i)
		if ((x / i) * i == x)
			return false;
	return true;
}
void dfs(int a, int num)
{
	if (a == k)
		if (isPrime(num))
			++ans;
		else
			;
	else
	{
		for (int i = 0; i < n; ++i)
			if (!vst[i])
			{
				vst[i] = true;
				dfs(a + 1, num + x[i]);
				vst[i] = false;
			}
	}
}
int main()
{
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i)
		std::cin >> x[i];
	dfs(0, 0);
	std::cout << ans / f[k] << std::endl;
	return 0;
}