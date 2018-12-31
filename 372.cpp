#include <iostream>
struct Data
{
	int a;
	bool b;
	Data();
};
int main()
{
	int n, t, m;
	std::cin >> n >> t >> m;
	Data *tx = new Data[n];
	for (int i = 0; i < n; ++i)
		std::cin >> tx[i].a;
	int d = t, ans = 0;
	for (int i = 0; i < m; ++i, d = t)
		for (int j = 0; j < n; ++j)
			if (tx[j].a <= d && tx[j].b)
			{
				d -= tx[j].a;
				std::cout << d << ' ' << i << ' ' << j << ' ' << tx[j].a << ' ' << ans << std::endl;
				++ans;
				tx[j].b = false;
			}
	std::cout << ans << std::endl;
	delete[] tx;
	return 0;
}
Data::Data()
{
	a = 0;
	b = true;
}