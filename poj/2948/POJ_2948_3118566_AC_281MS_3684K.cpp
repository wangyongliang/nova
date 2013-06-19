#include<stdio.h>
#define maxn 600
int a[maxn][maxn][2],sum[maxn][maxn][2],dp[maxn][maxn];
int n,m;
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int i,j,k;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j][0]);
				k+=a[i][j][0];
				if(i) sum[i][j][0]=sum[i-1][j][0]+k;
				else sum[i][j][0]=k;
			}
		}
		for(i=0;i<n;i++)
		{
			k=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j][1]);
				k+=a[i][j][1];
				if(i) sum[i][j][1]=sum[i-1][j][1]+k;
				else sum[i][j][1]=k;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				dp[i][j]=max(sum[i][j][0],sum[i][j][1]);
				if(i) dp[i][j]=max(dp[i-1][j]+sum[i][j][0]-sum[i-1][j][0],dp[i][j]);
				if(j) dp[i][j]=max(dp[i][j-1]+sum[i][j][1]-sum[i][j-1][1],dp[i][j]);
			}
		}
		printf("%d\n",dp[n-1][m-1]);
	}
	return 0;
}