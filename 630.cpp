#include <iostream>
#include <cstdio>
#include <string>
struct Point
{
	int x, y;
	Point() :x(0), y(0) {}
	Point(int a, int b) :x(a), y(b) {}
	Point &operator*=(int a)
	{
		x *= a;
		y *= a;
		return *this;
	}
};
int main()
{
	freopen("helmet.in", "r", stdin);
	freopen("helmet.out", "w", stdout);
	std::string code;
	int T;
	std::cin >> code >> T;
	int n = code.size();
	Point p(0, 0);
	for (int i = 0; i < n; ++i)
		switch (code[i])
		{
		case 'N':
			++p.y;
			break;
		case 'S':
			--p.y;
			break;
		case 'W':
			--p.x;
			break;
		case 'E':
			++p.x;
			break;
		}
	p *= (T / n);
	std::string remain = code.substr(0, T % n);
	n = remain.size();
	for (int i = 0; i < n; ++i)
		switch (remain[i])
		{
		case 'N':
			++p.y;
			break;
		case 'S':
			--p.y;
			break;
		case 'W':
			--p.x;
			break;
		case 'E':
			++p.x;
			break;
		}
	std::cout << p.x << ' ' << p.y << std::endl;
	return 0;
}