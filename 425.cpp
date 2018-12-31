#include <iostream>
#include <algorithm>
int main()
{
    using namespace std;
    unsigned short n,i;
    cin>>n;
    float *height=new float[n],a,b;
    for (i=0;i<n;i++)
        cin>>height[i];
    cin>>a>>b;
    unsigned short la=lower_bound(height,height+n,a)-height;
    unsigned short ub=upper_bound(height,height+n,b)-height;
    unsigned short ea=count(height,height+n,a);
    unsigned short eb=count(height,height+n,b);
    unsigned short ans=ub-la;
    cout<<ans<<' '<<ans-ea-eb<<' '<<ans-eb<<' '<<ans-ea<<endl;
    delete [] height;
    return 0;
}
