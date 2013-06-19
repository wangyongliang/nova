#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[310][310];
int n;
int min(int x,int y)
{
	return x>y?y:x;
}
int max(int x,int y)
{
	return x>y?x:y;
}
int inf=0x7fffffff;
int main()
{
	int m,i,j,k;
	int t;
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) a[i][j]=0x7fffffff;
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			a[i][j]=min(a[i][j],k);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[j][i]<inf)
				{
					for(k=1;k<=n;k++)
					{
						if(a[i][k]<inf) a[j][k]=min(a[j][k],max(a[j][i],a[i][k]));
					}
				}
			}
		}
		while(t--)
		{
			scanf("%d%d",&i,&j);
			if(a[i][j]==inf) printf("-1\n");
			else printf("%d\n",a[i][j]);
		}
	}
	return 0;
}
