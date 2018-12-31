#include <iostream>
int cnt[21],Money[21];
int main()
{
    using namespace std;
    int m,n;
    cin>>m>>n;
    int *Kind=new int[m],*Size=new int[n];
    int i;
    for (i=0;i<m;i++)
        cin>>Kind[i];
    for (i=0;i<m;i++)
        cin>>Money[Kind[i]-30];
    for (i=0;i<n;i++)
    {
        cin>>Size[i];
        cnt[Size[i]-30]++;
    }
    int s=0;
    for (i=0;i<=20;i++)
    {
        if (cnt[i]==0)
            continue;
        s+=2*Money[i]*cnt[i];
    }
    cout<<s<<endl;
    return 0;
}
