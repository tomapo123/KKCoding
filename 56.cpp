#include <iostream>
#include <utility>
#include <algorithm>
std::pair<int, int> p[105];
inline bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
	return a.first < b.first;
}
int main()
{
	int L, n;
	std::cin >> L >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> p[i].first >> p[i].second;
		if (p[i].first > p[i].second)
			std::swap(p[i].first, p[i].second);
	}
	sort(p + 1, p + 1 + n, cmp);
	int cnt = 0;
	int maxl = p[1].first, mr = p[1].second;
	for (int i = 2; i <= n; i++)
	{
		int l = p[i].first, r = p[i].second;
		if (l <= maxr) 
			maxr = std::max(maxr, r);
		else if (l > maxr)
			cnt += (maxr + 1 - maxl), maxl = l, maxr = r;
	}
	cnt += (maxr + 1 - maxl);
	std::cout << L + 1 - cnt << endl;
	return 0;
}