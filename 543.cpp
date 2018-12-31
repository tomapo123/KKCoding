#include <iostream>
#include <algorithm>
const int N = 3e5;
int n, k, l, r, x[N], q[N], m[N];
int main()
{
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> x[i];
		x[i] += x[i - 1];
	}
	for (int i = 1; i <= n; ++i)
	{
		while (l < r && i - q[l] >= k)
			++l;
		while (l < r && x[i] < x[q[r - 1]])
			--r;
		q[r++] = i;
		m[i] = x[q[l]];
	}
	for (int i = 1; i <= n; ++i)
		x[i] -= m[i - 1];
	std::cout << *std::max_element(x, x + n + 1);
}