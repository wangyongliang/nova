#include<stdio.h>
#define  maxn 100000
int dp[maxn][3];
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int a[maxn];
int main()
{
	int n,i,j,l;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			a[i]--;
			for(j=0;j<3;j++) dp[i][j]=100000;
		}
		int ans=1000000;
		for(i=0;i<3;i++) dp[0][i]=1;
		dp[0][a[0]]=0;
		for(i=1;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				for(l=0;l<=j;l++) dp[i][j]=min(dp[i-1][l]+(j!=a[i]),dp[i][j]);
			}
		}
		for(i=0;i<3;i++) ans=min(ans,dp[n-1][i]);
		for(i=1;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				dp[i][j]=1000000;
				for(l=j;l<3;l++) dp[i][j]=min(dp[i][j],dp[i-1][l]+(j!=a[i]));
			}
		}
		for(i=0;i<3;i++) ans=min(ans,dp[n-1][i]);
		printf("%d\n",ans);
	}
	return 0;
}