#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int t,i,j,n,min,ans,tp;
    int a[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",(a[n-1]-a[0])*2);
    }
    return 0;
}