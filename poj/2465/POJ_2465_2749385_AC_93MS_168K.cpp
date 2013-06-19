#include<stdio.h>
#define inf 9999999
int main()
{
	int a[110][2],dp[110][210];
	int i,j,k,m,n;
	int sum;
	scanf("%d",&m);
	{
		k=1;
		a[0][0]=0;
		a[0][1]=inf;
		while(scanf("%d%d",&a[k][0],&a[k][1])!=EOF)
		{
			
			if(a[k][0]==-1) break;
			if(a[k][0]==a[k-1][0])
			{
				if(a[k-1][1]>a[k][1]) a[k-1][1]=a[k][1];
			}
			else k++;
		}
		n=k;
		for(i=0;i<101;i++)
		{
			for(j=0;j<201;j++) dp[i][j]=inf;
		}
		dp[0][100]=0;
		if(a[1][0]!=inf) i=0;
		else i=1;
		for(;i<n;i++)
		{
			for(j=0;j<201;j++)
			{
				for(k=0;k<j;k++)
				{
					if(dp[i][j]>dp[i][k]+a[i][1]*(j-k)) dp[i][j]=dp[i][k]+a[i][1]*(j-k);
				}
			}
			for(j=0;j<201;j++)
			{
				for(k=1;k<n;k++)
				{
					sum=a[k][0]-a[i][0];
					if(sum<=j)
					{
						if(dp[k][j-sum]>dp[i][j]) dp[k][j-sum]=dp[i][j];
					}
				}
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
