#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 4010
int a[maxn],b[maxn],c[maxn],d[maxn];
int p[maxn*maxn];
int cnt[maxn*maxn];
int main()
{
	int n;
	int i,j,k;
	int min,max,mid,ans,q;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{ 
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        }
        for(k=i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                p[k]=a[i]+b[j];
                cnt[k++]=0;
            }
        }
        sort(p,p+k);
        for(j=0,cnt[0]=i=1;i<k;i++)
        {
            if(p[i]==p[j]) cnt[j]++;
            else p[++j]=p[i],cnt[j]=1;
        }
        k=j;
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                q=-(c[i]+d[j]);
                min=0;
                max=k;
                while(min<max)
                {
                    mid=(min+max)/2;
                    if(p[mid]==q) min=max=mid;
                    else if(p[mid]>q) max=mid;
                    else min=mid+1;
                }
                if(p[min]==q)  ans+=cnt[min];
            }
        }
        printf("%d\n",ans);
	}
	return 0;
}
