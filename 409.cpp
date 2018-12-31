#include <iostream>
int *cnt=new int[102],*Ncnt=new int[101];
int main()
{
    using namespace std;
    int n,i;
    cin>>n;
    int *score=new int[n];
    for (i=0;i<n;i++)
    {
        cin>>score[i];
        cnt[score[i]]++;
    }
    *Ncnt=*cnt;
    int k;
    for (i=100;i>=0;i--)
        if (cnt[i]!=0)
        {
            k=i;
            break;
        }
    Ncnt[k]=1;
    for (i=k-1;i>=0;i--)
    {
        Ncnt[i]=cnt[i+1]+Ncnt[i+1];
    }
    for (i=0;i<n;i++)
        cout<<Ncnt[score[i]]<<" ";
    delete [] score;
    delete [] Ncnt;
    delete [] cnt;
    return 0;
}
