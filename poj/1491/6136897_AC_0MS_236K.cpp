#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return gcd(b,a%b);
    }
    

}
int main()
{
    int n;
    int cnt;
    int a[100];
    int i,j;
    while(cin>>n)
    {
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(gcd(a[i],a[j])==1)
                {
                    cnt++;
                }
            }
        }
        if(cnt==0){
            printf("No estimate for this data set.\n");
            continue;
        }
//        cout<<cnt<<endl;
        double ans=n*(n-1)/2;
        ans=ans*6.0/cnt;
        ans=sqrt(ans);
        printf("%.6lf\n",ans);
    }
    return 0;
}
