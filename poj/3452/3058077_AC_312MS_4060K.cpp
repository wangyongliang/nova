#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 200000+10
int a[maxn],b[maxn],cnt[maxn];
struct node
{
	int x,y;
}ans[maxn];
bool cmp(const node &x,const node &y)
{
	return x.x<y.x;
}
int main()
{
	int n,m,i,j,k;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=1;i<=n;i++) cnt[i]=a[i]=0;
		k=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			ans[i].x=b[i];
			ans[i].y=i;
		}
		sort(ans,ans+n,cmp);
		b[ans[0].y]=1;
		for(k=i=1;i<n;i++)
		{
			if(ans[i].x!=ans[i-1].x)k++;
			b[ans[i].y]=k;
		}
		for(i=0;i<n;i++)
		{
			cnt[b[i]]++;
		}
		k=1;
		for(i=0;i<n&&k<=m+1;i++)
		{
			if(a[b[i]]==0)
			{
				if(b[i]==1) 
				{
					a[1]=k++;
				}
				else
				{
					if(a[b[i]-1]) a[b[i]]=a[b[i]-1];
					else a[b[i]]=k++;
				}
			}
		}
		if(k<=m+1)
		{
			for(i=0;i<n;i++) printf("%d ",a[b[i]]);
			printf("\n");
			for(i=1;i<=n;i++)
			{
				while(cnt[i]--) printf("%d ",a[i]);
			}
			printf("\n");
		}
		else printf("Transportation failed\n");
	}
	return 0;
}