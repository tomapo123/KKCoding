#include <iostream>
#define REPEAT(X, N) for (int X = 0; X < N; ++X)
#define INVREPEAT(X, N) for (int X = N - 1; i + 1; --i)
const int N = 1e6;
int n, x[N], y[N], q[N], al[N], ar[N], a, b, l, r, j;
int main()
{
	std::cin >> n >> a >> b;
	REPEAT(i, n)
		std::cin >> x[i];
	REPEAT(i, n)
		std::cin >> y[i];
	REPEAT(i, n)
	{
		while (j <= i && x[i] - x[j] >= a)
		{
			while (l < r && y[j] > y[q[r - 1]])
				--r;
			q[r++] = j++;
		}
		while (l < r && x[i] - x[q[l]] > b)
			++l;
		al[i] = (l < r ? y[q[l]] : -1);
	}
	l = r = 0;
	j = n - 1;
	INVREPEAT(i, n)
	{
		while (j >= i && x[j] - x[i] >= a)
		{
			while (l < r && y[j] > y[q[r - 1]])
				--r;
			q[r++] = j--;
		}
		while (l < r && x[q[l]] - x[i] > b)
			++l;
		ar[i] = (l < r ? y[q[l]] : -1);
	}
	REPEAT(i, n)
		std::cout << (ar[i] > al[i] ? ar[i] : al[i]) << ' ';
	//\
	return 0;
}