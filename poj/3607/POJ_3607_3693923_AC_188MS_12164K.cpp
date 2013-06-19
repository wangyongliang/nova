#include<stdio.h>
#define maxn 1010
int c[maxn][maxn];
int dp[maxn][maxn];
int s[maxn][maxn];
int mod=9973;
int main()
{
	int i,j;
	int n,m,k;
	int t;
	for(i=0;i<maxn;i++)
	{
		for(j=0;j<maxn;j++)s[i][j]= c[i][j]=0;
	}
	s[0][0]=c[0][0]=1;
	for(i=1;i<maxn;i++)
	{
		c[i][0]=1;
		s[i][0]=0;
		for(j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%mod;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(n==0&&m==0&&k==0) while(1);
		if(k==0)
		{
			int ans=0;
			if(n==0) while(1);
			for(i=1;i<=m;i++) ans=(ans+s[n][i])%mod;
			printf("%d\n",ans);
		}
		else{
		for(i=0;i<maxn;i++)
		{
			for(j=0;j<maxn;j++) dp[i][j]=0;
		}
		dp[0][0]=1;
		for(i=1;i<=m;i++)
		{
			for(j=0;j<i*k;j++) dp[i][j]=0;
			for(;j<=n;j++)  dp[i][j]=(c[j-1][k-1]*dp[i-1][j-k]+i*dp[i][j-1])%mod;
		}
		printf("%d\n",dp[m][n]);
		}
	}
	return 0;
}