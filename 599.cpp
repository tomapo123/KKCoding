#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
const int N = 1e5;
int n, nowComplaint = 0, maxComplaint = 0, finish = 0, id[N];
bool atUse[N];
struct Complaint
{
	int start, end;
} c[N];
struct
{
	bool operator()(const Complaint &lhs, const Complaint &rhs) const
	{
		return lhs.start < rhs.start;
	}
} cmp;
std::multiset<int> s;
int main()
{
	freopen("shield.in", "r", stdin);
	freopen("shield.out", "w", stdout);
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> c[i].start >> c[i].end;
		if (c[i].end > finish)
			finish = c[i].end;
	}
	std::sort(c, c + n, cmp);
	for (int i = 0; i < n; ++i)
		id[i] = c[i].start;
	for (int t = c[0].start, i = 0; t <= finish; ++t)
	{
		while (t == id[i])
		{
			++nowComplaint;
			s.insert(c[i++].end + 1);
		}
		if (s.find(t) != s.end())
		{
			nowComplaint -= s.count(t);
			s.erase(t);
		}
		if (nowComplaint > maxComplaint)
			maxComplaint = nowComplaint;
	}
	std::cout << maxComplaint << std::endl;
	return 0;
}