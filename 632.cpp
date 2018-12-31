#include <iostream>
#include <algorithm>
const int N = 3e5;
int n, k, x[N], m[N];
int main()
{
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> x[i];
		x[i] += x[i - 1];
		m[i] = std::min(m[i - 1], x[i]);
	}
	for (int i = k; i <= n; ++i)
		x[i] -= m[i - k];
	std::cout << *std::max_element(x + k, x + n + 2) << std::endl;
	//\
	return 0;
}