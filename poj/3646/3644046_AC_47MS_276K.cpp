#include<stdio.h>
#include<algorithm>
using namespace std;
int a[20000+10];
int b[20000+10];
int main()
{
    int n,m,i,j;
    __int64 ans;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<m;i++) scanf("%d",&b[i]);
        if(m<n) printf("Loowater is doomed!\n");
        else
        {
            sort(a,a+n);
            sort(b,b+m);
            ans=0;
            for(i=j=0;i<n;i++)
            {
                for(;j<m;j++)
                {
                    if(b[j]>=a[i]) break;
                }
                if(j<m) ans+=b[j++];
                else 
                {
                    ans=-1;
                    break;
                }
            }
            if(ans==-1) printf("Loowater is doomed!\n");
            else printf("%I64d\n",ans);
        }
    }
}
