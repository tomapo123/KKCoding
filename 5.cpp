#include <iostream>
#include <algorithm>
const int N = 5e4;
int Min[N], Max[N], n, c[N];
int main()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> c[i];
	Min[0] = Max[0] = c[0];
	for (int i = 1; i < n; ++i)
		Min[i] = std::min(Min[i - 1], c[i]), Max[i] = std::max(Max[i - 1], c[i]);
	int s = c[0];
	for (int i = 1; i < n; ++i)
		s += (std::min(abs(c[i] - Min[i - 1]), abs(c[i] - Max[i - 1]));
	std::cout << s << std::endl;
	return 0;
}