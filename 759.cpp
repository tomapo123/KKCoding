#include <iostream>
#include <algorithm>
#include <cstdlib>
int main()
{
	freopen("eagle.in", "r", stdin);
	freopen("eagle.out", "w", stdout);
	int x, y, u, v, d;
	std::cin >> x >> y >> u >> v;
	if (u <= v)
		std::cout << "never" << std::endl;
	else
	{
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout.precision(2);
		std::cout << double(std::min(std::abs(x % 100 - y % 100), 100 - std::abs(x % 100 - y % 100))) / (u - v) << std::endl;
	}
	return 0;
}