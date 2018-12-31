#include <iostream>
#include <set>
int n, m[N];
std::set<int> p;
int main()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> m[i];
		p.insert(i + 1);
	}
	for (int i = 0; i < n; ++i)
	{
		std::set<int>::iterator itr = p.upper_bound(m[i]);
		if (itr != p.begin())
			p.erase(--itr);
	}
	std::cout << p.size() << std::endl;
	return 0;
}