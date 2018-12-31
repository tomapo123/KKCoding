#include <iostream>
#include <algorithm>
#include <numeric>
const int N = 1e6;
int n, p, a[N];
int main()
{
	std::cin >> n >> p;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::adjacent_difference(a, a + n, a);
	for (int i = 0, x, y, z; i < p; ++i)
	{
		std::cin >> x >> y >> z;
		if (x > y)
			std::swap(x, y);
		a[x - 1] += z;
		a[y] -= z;
	}
	std::partial_sum(a, a + n, a);
	std::cout << *std::min_element(a, a + n) << std::endl;
	return 0;
}