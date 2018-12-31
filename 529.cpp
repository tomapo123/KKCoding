#include <iostream>
#include <algorithm>
#include <vector>
const int N = 50;
int n;
int a[N];
int ans;
bool isValid(int x);
int main()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	int x = *std::max_element(a, a + n);
	while (!isValid(x))
		continue;
	std::cout << ans << std::endl;
}
bool isValid(int x)
{
	return true;
}