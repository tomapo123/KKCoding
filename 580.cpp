#include <iostream>
#include <algorithm>
const long long N = 5e6;
long long n, t[N];
struct Stone
{
	long long t, d;
} s[N];
bool operator<(Stone lhs, Stone rhs)
{
	return (double)lhs.t / lhs.d < (double)rhs.t / rhs.d;
}
int main()
{
	freopen("sandal.in", "r", stdin);
	freopen("sandal.out", "w", stdout);
	std::cin >> n;
	for (long long i = 0; i < n; ++i)
		std::cin >> s[i].t >> s[i].d;
	std::sort(s, s + n);
	t[0] = 0;
	for (long long i = 1; i < n; ++i)
		t[i] = t[i - 1] + s[i - 1].t * 2;
	for (long long i = 0; i < n; ++i)
		t[n] += t[i] * s[i].d;
	std::cout << t[n] << std::endl;
	return 0;
}