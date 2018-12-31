#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

const int N = 100;

long long id[26];
std::vector<char> iesl; //Inequations Left
std::vector<char> iesr; //Inequations Right
int n;

long long getAncestor(long long x)
{
	return id[x] == x ? x : (id[x] = getAncestor(id[x]));
}
void unite(long long x, long long y)
{
	id[getAncestor(x)] = getAncestor(y);
}
void initId()
{
	for (int i = 0; i < 26; ++i)
		id[i] = i;
}
void error()
{
	std::cout << "Impossible" << std::endl;
	exit(0);
}

int main()
{
	std::cin >> n;
	initId();
	char a, b, c, d;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a >> b >> c >> d;
		if (b == '=')
			unite(a - 'a', d - 'a');
		else //b == '!'
			if (a == d)
				error();
			else //a != d
			{
				iesl.push_back(a - 'a');
				iesr.push_back(d - 'a');
			}
	}
	int nn = iesl.size();
	for (int i = 0; i < nn; ++i)
		if (getAncestor(iesl[i]) == getAncestor(iesr[i]))
			error();
	std::cout << "Possible" << std::endl;
}