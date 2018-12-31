#include <set>
#include <iostream>
#include <algorithm>
int main()
{
	int m, n, x = 0;
	std::cin >> m >> n;
	int *a = new int[m];
	int *b = new int[n];
	for (int i = 0; i < m; ++i)
		std::cin >> a[i];
	for (int i = 0; i < n; ++i)
		std::cin >> b[i];
	std::multiset<int> s;
	std::multiset<int>::iterator itr = s.begin();
	for (int i = 0; i < std::max(m, n); ++i)
	{
		if (i < m)
			s.insert(a[i]);
		for (int j = x; j < m; ++j)
		{
			if (i == b[j])
			{
				x = j + 1;
				std::cout << *itr << std::endl;
				++itr;
			}
			else if (i < b[j])
				break;
#ifdef DEBUG
			std::cout << i << ' ' << j << ' ' << b[j] << ' ' << a[i];
#endif
		}
	}
}