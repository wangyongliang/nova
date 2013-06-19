#include<stdio.h>
#define inf 9999999
int main()
{
	int a[110][2],dp[110][210];
	int n,m,i,j,k;
	scanf("%d",&m);
	{

		for(i=0;i<101;i++)
		{
			for(j=0;j<201;j++) dp[i][j]=inf;
		}
		k=1;
		a[0][0]=0;
		a[0][1]=inf;
		while(scanf("%d%d",&a[k][0],&a[k][1])!=EOF)
		{
			if(a[k][0]==-1) break;
			if(a[k][0]==a[k-1][0])
			{
				if(a[k][1]<a[k-1][1]) a[k-1][1]=a[k][1];
			}
			else k++;
		}
		n=k;
		dp[0][100]=0;
		if(a[0][1]<inf)
		{
			for(i=100;i<201;i++) dp[0][i]=a[0][1]*(i-100);
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<201;j++)
			{
				if(j+a[i][0]-a[i-1][0]<=200)
				{
					if(dp[i][j]>dp[i-1][j+a[i][0]-a[i-1][0]])
						dp[i][j]=dp[i-1][j+a[i][0]-a[i-1][0]];
				}
			}
			for(j=1;j<201;j++)
			{
				if(dp[i][j]>dp[i][j-1]+a[i][1]) dp[i][j]=dp[i][j-1]+a[i][1];

			}
		}
		k=inf;
		for(i=100+m-a[n-1][0];i<201;i++)
		{
			if(k>dp[n-1][i]) k=dp[n-1][i];
		}
		if(k==inf) printf("Impossible\n");
		else printf("%d\n",k);
	}
	return 0;
}