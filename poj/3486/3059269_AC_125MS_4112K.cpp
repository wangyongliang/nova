#include<stdio.h>
#define maxn 1000+10
int a[maxn][maxn];
int ans[maxn];
int main()
{
	int c,n,i,j,k;
	while(scanf("%d",&c)!=EOF)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++) scanf("%d",&a[i][j]);
		}
		for(i=1;i<=n;i++) ans[i]=1000000;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				if(ans[j]>ans[i-1]+c+a[i][j]) ans[j]=ans[i-1]+c+a[i][j];
			}
		}
		printf("%d\n",ans[n]);
	}
	return 0;
}