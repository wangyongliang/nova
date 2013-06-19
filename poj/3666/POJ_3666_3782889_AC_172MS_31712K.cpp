#include<stdio.h>
#include<algorithm>
using namespace std;
__int64 dp[2010][2010];
__int64 tp[2010];
__int64 min(__int64 x,__int64 y)
{
	if(x>y) return y;
	else return x;
}
int n;
int a[2010],b[2010];
__int64 abs(__int64 x)
{
	if(x>0) return x;
	else return -x;
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b,b+n);
		for(i=0;i<n;i++) dp[0][i]=abs(b[i]-a[0]);
		for(i=1,tp[0]=dp[0][0];i<n;i++) tp[i]=min(tp[i-1],dp[0][i]);
		for(i=1;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dp[i][j]=abs(a[i]-b[j])+tp[j];
			}
			tp[0]=dp[i][0];
			for(j=1;j<n;j++) tp[j]=min(tp[j-1],dp[i][j]);
		}
		__int64 ans=dp[n-1][0];
		for(i=1;i<n;i++) ans=min(ans,dp[n-1][i]);
		for(i=n-2,tp[n-1]=dp[0][n-1];i>=0;i--) tp[i]=min(tp[i+1],dp[0][i]);
		for(i=1;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dp[i][j]=abs(a[i]-b[j])+tp[j];
			}
			for(j=n-2,tp[n-1]=dp[i][n-1];j>=0;j--) tp[j]=min(tp[j+1],dp[i][j]);
		}
		for(i=1;i<n;i++) ans=min(ans,dp[n-1][i]);
		printf("%I64d\n",ans);
	}
	return 0;
}