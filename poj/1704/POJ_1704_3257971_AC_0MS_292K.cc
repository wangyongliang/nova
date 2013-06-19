#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[1100];
    int n,i,j,k;
    int ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        if(n%2==1)ans=a[0]-1,i=2;
        else ans=0,i=1;
        for(;i<n;i+=2)
        {
            ans^=(a[i]-a[i-1]-1);
        }
        if(ans) printf("Georgia will win\n");
        else printf("Bob will win\n");
    }
    return 0;
}

