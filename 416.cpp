#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
const int Infinity = 1e9;
int n, x, y, ans = Infinity, t;
int main()
{
	std::cin >> n >> x >> y;
	for (int a = 0; a <= n; ++a)
	{
		t = 0;
		bool changed = false;
		if ((x - 2 * (n - a)) >= 0)
		{
			t += ceil((x - 2 * (n - a)) / 3.0);
			changed = true;
		}
		if ((y - a) >= 0)
		{
			t += ceil((y - a) / 2.0);
			changed = true;
		}
		if (changed && t < ans)
			ans = t;
		if ((double)clock() / CLOCKS_PER_SEC * 1000 >= 883)
			break;
	}
	std::cout << ans + n << std::endl;
	return 0;
}