#include<stdio.h>
int dp[10010][510][2];
int d[10010];
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int n,i,j,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",&d[i]);
		for(i=0;i<=500;i++) dp[0][i][0]=dp[0][i][1]=0;
		dp[0][1][0]=d[0];
		dp[0][1][1]=d[0];
		for(i=1;i<n;i++)
		{
			dp[i][0][0]=dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][1]);
			for(j=1;j<m;j++)
			{
				dp[i][j][0]=dp[i-1][j-1][0]+d[i];
				dp[i][j][1]=max(dp[i][j][0],dp[i-1][j+1][1]);
			}
			dp[i][m][0]=dp[i-1][m-1][0]+d[i];
			dp[i][m][1]=dp[i][m][0];
		}
		printf("%d\n",max(dp[n-1][0][0],dp[n-1][0][1]));
	}
	return 0;
}