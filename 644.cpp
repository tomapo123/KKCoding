//DFS: Depth First Search
#include <iostream>
#include <vector>
const int N = 1e5;
int n, m, a, b, isBiG;
int vst[N];
std::vector<int> es[N];
typedef int Color;
void dfs(int u, Color color)
{
	if (isBiG)
	{
		vst[u] = color;
		for (int i = 0; i < es[u].size(); ++i)
			if (!vst[es[u][i]])
				dfs(es[u][i], 3 - color);
			else if (vst[es[u][i]] == color)
				isBiG = false;
	}
}
int main()
{
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		std::cin >> a >> b;
		es[a].push_back(b);
		es[b].push_back(a);
	}
	isBiG = 1;
	for (int i = 1; i <= n && isBiG; ++i)
		if (!vst[i])
			dfs(i, 1);
	std::cout << (isBiG ? "Yes" : "No") << std::endl;
}
//UFDS: Unite-Find Disjoint Set
/*
#include <iostream>
const int N = 1e5;
int n, m, id[N];
int getAncestor(int x)
{
return id[x] == x ? x : id[x] = getAncestor(id[x]);
}
void unite(int x, int y)
{
id[getAncestor(x)] = getAncestor(y);

}
int main()
{
std::cin >> n >> m;
for (int i = 1; i <= n * 2; ++i)
id[i] = i;
bool isBiG = true;
for (int i = 0, a, b; i < m; ++i)
{
std::cin >> a >> b;
if (getAncestor(a) == getAncestor(b))
{
isBiG = false;
break;
}
unite(a, b + n);
unite(b, a + n);
}
std::cout << (isBiG ? "Yes" : "No");
return 0;
}
*/