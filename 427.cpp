#include <iostream>
#include <cmath>
const double SQRT2=std::sqrt(2.0);
int main()
{
    using namespace std;
    int a;
    cin>>a;
    double r=(7+27*a)*SQRT2/8.0;
    double k=pow(r+sqrt(r*r+1),1.0/3);
    double x=(-1+SQRT2*(k-1.0/k))/3.0;
    cout.setf(ios_base::showpoint);
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout.precision(3);
    cout<<x<<endl;
    return 0;
}
