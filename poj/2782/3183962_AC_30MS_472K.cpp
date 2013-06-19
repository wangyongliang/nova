#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 100010
int a[maxn];
int main()
{
    int i,j,k,n,l;
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int ans=0;
        for(i=n-1,j=0;i>=j;i--)
        {
            if(i==j) 
            {
                ans++;
                continue;
            } 
            if(a[i]+a[j]>l) ans++;
            else 
            {
                ans++;
                j++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
