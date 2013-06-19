#include<stdio.h>
#include<stdlib.h>
#define maxn 1100
double p[maxn][40];
double dp[maxn][40];

int main()
{
	int n,m,t;
	double a[31];
	int i,j,k;
	while(scanf("%d%d%d",&m,&t,&n)&&(n+m+t))
	{
		for(i=0;i<t;i++)
		{
			for(j=0;j<m;j++) scanf("%lf",&a[j]);
			for(j=0;j<m;j++)
			{
				for(k=0;k<=m;k++) dp[j][k]=0.0;
			}
			dp[0][1]=a[0];
			dp[0][0]=1-a[0];
			for(j=1;j<m;j++)
			{
				for(k=0;k<=m;k++)
				{
					dp[j][k]=dp[j-1][k]*(1-a[j]);
					if(k)dp[j][k]+=dp[j-1][k-1]*a[j];
				}
			}
			for(j=0;j<=m;j++) 
			{
				p[i][j]=dp[m-1][j];
		//		printf("%lf ",p[i][j]);
			}
		//	printf("\n");
		}
		for(i=1;i<=m;i++) dp[0][i]=p[0][i];
		for(i=1;i<t;i++)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=0.0;
				for(k=1;k<j;k++) dp[i][j]+=p[i][k]*dp[i-1][j];
				for(k=1;k<=j;k++) dp[i][j]+=p[i][j]*dp[i-1][k];
			}
		}
		double ans=0.0;
		for(i=n;i<=m;i++) ans+=dp[t-1][i];
		printf("%.3lf\n",ans);
	}
	system("pause");
	return 0;
}