#include <iostream>
int Min(int *,int ,int );
int cnt[4];
int main()
{
    using namespace std;
    char c;
    while (cin>>c)
        if (c!='l' && c!='o' && c!='v' && c!='e' && c!='w')
            continue;
        else
            switch (c)
            {
                case 'l':++cnt[0];break;
                case 'o':++cnt[1];break;
                case 'v':++cnt[2];break;
                case 'e':++cnt[3];break;
                case 'w':cnt[2]+=2;break;
            }
    int m=Min(cnt,0,3);
    cout<<cnt[m]<<endl;
    return 0;
}
int Min(int *a,int i,int j)
{
    if (i==j)
        return j;
    int m=(i+j)>>1;
    int x=Min(a,i,m);
    int y=Min(a,m+1,j);
    return a[x]>a[y]?y:x;
}
