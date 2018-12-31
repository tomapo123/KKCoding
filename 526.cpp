#include <iostream>
#include <cmath>
int h;
double l;
int main()
{
	std::cin >> h >> l;
	int x = round(l / 15) + h - 8;
	std::cout << x + (x < 0 ? 24 : 0) << std::endl;
}