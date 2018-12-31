#include <iostream>
#include <algorithm>
int main()
{
    using namespace std;
    int m,a,b,i,r=0;
    cin>>m>>a>>b;
    int *s=new int[a];
    int *p=new int[b];
    for (i=0;i<a;i++)
        cin>>s[i];
    for (i=0;i<b;i++)
        cin>>p[i];
    sort(s,s+a);
    sort(p,p+b);
    for (i=0;i<a;i++)
        r+=upper_bound(p,p+b,m-s[i])-p;
    cout<<r<<endl;
    delete [] s;
    delete [] p;
    return 0;
}
