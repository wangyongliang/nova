#include<stdio.h>
#define maxn 5000+10
int dp[maxn][2];
int a[maxn];
int flag[65536+10];
bool flg[65536+10];
int main()
{
	int i,j,n;
	int max,max_cnt;
	int ans,cnt;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			dp[i][0]=dp[i][1]=0;
		}
		for(i=0;i<65536+10;i++) flg[i]=flag[i]=0;
		ans=cnt=0;
		for(i=0;i<n;i++)
		{
			max=0;max_cnt=1;
			for(j=flag[a[i]];j<i;j++)
			{
				if(a[j]>a[i]&&dp[j][0]>=max)
				{
					if(dp[j][0]>max) 
					{
						max=dp[j][0];
						max_cnt=dp[j][1];
					}
					else max_cnt+=dp[j][1];
				}
			}
			flag[a[i]]=i;
			max++;
			if(max==1&&flg[a[i]]) dp[i][0]=-1;
			else{
			dp[i][0]=max;
			dp[i][1]=max_cnt;
			ans=ans<max?max:ans;
			}
			flg[a[i]]=1;
		}
		for(i=0;i<n;i++)
		{
			if(dp[i][0]==ans) cnt+=dp[i][1];
		}
		printf("%d %d\n",ans,cnt);
	}
	return 0;
}