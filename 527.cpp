#include <iostream>
const int N = 10000;
const int H = 1000;
int n, q;
int h[H][H], x1[N], x2[N], y1[N], y2[N];
unsigned long long calc(int x1, int y1, int x2, int y2);
int main()
{
	std::cin >> n >> q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> h[i][j];
	for (int i = 0; i < q; ++i)
		std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			h[i][j] += (j >= 1 ? h[i][j - 1] : 0);
	bool z = false;
	for (int i = 0; i < q; ++i)
	{
		if (z)
			std::cout << std::endl;
		else
			z = true;
		std::cout << calc(x1[i], y1[i], x2[i], y2[i]);
	}
}
unsigned long long calc(int x1, int y1, int x2, int y2)
{
	unsigned long long ret_val = 0;
	for (int i = x1; i <= x2; ++i)
		ret_val += h[i][y2] - (y1 >= 1 ? h[i][y1 - 1] : 0);
}