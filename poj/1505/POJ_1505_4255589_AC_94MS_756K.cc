#include<stdio.h>
int a[600];
int b[600];
int dp[600][600];
long long sum[600];
int main()
{
	int t;
	scanf("%d",&t);
	int i,n,m,k,j;
	while(t--)	
	{
		scanf("%d%d",&n,&m);

		long long min,max,mid;
		min=max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i) sum[i]=sum[i-1]+a[i];
			else sum[i]=a[i];
			max+=a[i];
			if(a[i]>=min) min=a[i];
		}
				if(m==1)
		{
			printf("%d",a[0]);
			for(i=1;i<n;i++) printf(" %d",a[i]);
			printf("\n");
			continue;
		}
		while(min<max)
		{
			mid=(min+max)/2;
			long long tp=0;
			int cnt=0;
			for(i=0;i<n;i++)
			{
				if(tp+a[i]<=mid) tp+=a[i];
				else
				{
					tp=a[i];
					cnt++;
				}
			}
			if(tp) cnt++;
			if(cnt<=m) max=mid;
			else min=mid+1;
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++) dp[i][j]=-1;
		}
		for(i=n-1;i>=0;i--)
		{
			if(sum[n-1]-sum[i]+a[i]<=min) dp[m-1][i]=n;
		}
		for(i=m-1;i>0;i--)
		{
			for(j=n-1;j>0;j--)
			{
				if(dp[i][j]>0)
				{
					for(k=j-1;k>=0;k--)
					{
						if(sum[j-1]-sum[k]+a[k]<=min) 
						{
							if(dp[i-1][k]==-1)dp[i-1][k]=j;
							else if(dp[i-1][k]>j) dp[i-1][k]=j;
						}
						else break;
					}
				}
			}
		}
		printf("%d",a[0]);
		for(i=1;i<dp[0][0];i++) printf(" %d",a[i]);
		printf(" /");
		int cur=dp[0][0];
		for(i=1;i<m;i++)
		{
			for(j=cur;j<dp[i][cur];j++) printf(" %d",a[j]);
			if(i!=m-1)		printf(" /");
			cur=dp[i][cur];
		}
		//printf("")
		printf(" \n");
	}
	return 0;
}