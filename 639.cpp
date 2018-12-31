#include <cstdio>
#include <ctime>
#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif
const int N = 5e5;
int n, k, x[N];
double ans = 0;
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &x[i]);
	for (int i = 1; i < n; ++i)
		x[i] += x[i - 1];
	for (int s = 0; s <= n - k; ++s)
		for (int l = k; s + l <= n; ++l)
		{
			double t = (double(x[s + l - 1] - (s != 0 ? x[s - 1] : 0))) / l;
			if (t > ans)
				ans = t;
			if (double(clock()) / CLOCKS_PER_SEC * 1000 >= 980)
			{
				printf("%.2lf", ans);
				return 0;
			}
		}
	printf("%.2lf", ans);
	return 0;
}