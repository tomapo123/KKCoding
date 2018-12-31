#include <iostream>
#include <set>
std::multiset<int> s;
int n, w;
int main()
{
	freopen("souvenir.in", "r", stdin);
	freopen("souvenir.out", "w", stdout);
	std::cin >> w >> n;
	for (int i = 0, t; i<n; ++i)
	{
		std::cin >> t;
		s.insert(t);
	}
	int cnt = 0;
	for (; !s.empty(); ++cnt)
	{
		int x = *s.begin();
		std::multiset<int>::iterator p = s.upper_bound(w - x);
		if (p == s.begin())
			s.erase(p);
		else if (--p == s.begin())
			s.erase(s.find(x));
		else
		{
			s.erase(p);
			s.erase(s.find(x));
		}
	}
	std::cout << cnt << std::endl;
	return 0;
}