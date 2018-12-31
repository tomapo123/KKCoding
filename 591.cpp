#include <iostream>
const int N=500;
const int Infinity=1e9;
typedef char Gyne[5];
Gyne s[N];
int n,ans=Infinity;
bool vst[N];
int order[N];
int Kruskal(const Gyne a, const Gyne b)
{
}
void dfs(int x)
{
    if (x==n)
    {

    }
    for (int i=0;i<n;++i)
        if (!vst[i])
        {
            vst[i]=true;
            order[x]=i;
            dfs(x+1);
            vst[i]=false;
        }
}
int main()
{
    std::cin>>n;
    for (int i=0;i<n;++i)
        std::cin>>s[i];
    dfs(0);
    std::cout<<ans<<std::endl;
}