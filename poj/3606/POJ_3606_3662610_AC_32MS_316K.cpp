#include<stdio.h>
int a[10010];
int dp[10010][3];
int mod=9973;
int n;
void dfs(int i)
{
	if(i*2>=n)
	{
					if(a[i]==1) dp[i][0]=3,dp[i][1]=1,dp[i][2]=1;
			else dp[i][0]=1,dp[i][1]=3,dp[i][2]=1;
	}
	else
	{
		dfs(i*2);
		dfs(i*2+1);
		int			j=i*2;
		int	k=i*2+1;
		if(a[i]==1)
		{
			dp[i][0]=dp[j][0]*(dp[k][0]+dp[k][1])+dp[j][1]*dp[k][0];
			dp[i][1]=dp[j][1]*dp[k][1];
			dp[i][2]=dp[j][1]*dp[k][2];
		}
		else
		{
			dp[i][0]=dp[j][0]*dp[k][0];
			dp[i][1]=dp[j][1]*(dp[k][0]+dp[k][1])+dp[j][0]*dp[k][1];
			dp[i][2]=dp[j][0]*dp[k][2];
		}
		for(j=0;j<3;j++) dp[i][j]%=mod;
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++) scanf("%d",&a[i]);
		dfs(1);
		printf("%d %d\n",dp[1][2],((dp[1][2]-1)%mod+mod)%mod);
	}
	return 0;
}