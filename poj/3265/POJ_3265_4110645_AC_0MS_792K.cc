#include<stdio.h>
int dp[400][400];
int a[400],b[400];
int suma[400],sumb[400];
int main()
{
	int  n,m,i,j;
	int k;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		
		suma[0]=sumb[0]=a[0]=b[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			if(i) 
			{
				suma[i]=a[i]+suma[i-1];
				sumb[i]=b[i]+sumb[i-1];
			}
			else
			{
				suma[i]=a[i];
				sumb[i]=b[i];
			}
		//	for(j=0;j<=n;j++) dp[i][j]=1000;
		}
		a[n+1]=b[n+1]=0;
		n++;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++) dp[i][j]=10000;
		}
		int sum1=0,sum2;
		for(i=1;i<=n;i++)
		{
			sum1+=a[i];
			if(sum1>m) break;
			dp[0][i]=2;
		}
		for(i=0;i<=n;i++)
		{
			sum1=sum2=0;
			for(j=i;j<=n;j++)
			{
				sum1=0;
				sum2=sumb[j]-sumb[i];
				if(sum2<=m&&dp[j][j]>dp[i][j]+1) dp[j][j]=dp[i][j]+1;
				for(k=j+1;k<=n;k++)
				{
					sum1+=a[k];
					if(sum1+sum2>m) break;
					if(sum1+sum2<=m&&dp[j][k]>dp[i][j]+1)
					{
					//	if(j==n-1&&k==)
					//		printf("");
						dp[j][k]=dp[i][j]+1;
					}
				}
			}
		}
		printf("%d\n",dp[n-1][n-1]);
	}
	return 0;
}