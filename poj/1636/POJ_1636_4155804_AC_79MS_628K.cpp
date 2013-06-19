#include<stdio.h>
#include<vector>
using namespace std;
int flag1[300],flag2[300];
vector<int> a[300],b[300];
int dp[300][300];
int cnt1,cnt2;
void dfs(int x,int flag)
{
	int i;
	if(flag==0)
	{
		flag1[x]=0;
		cnt1++;
		for(i=0;i<a[x].size();i++)
		{
			if(flag2[a[x][i]]) dfs(a[x][i],1-flag);
		}
	}
	else
	{
		flag2[x]=0;
		cnt2++;
		for(i=0;i<b[x].size();i++)
		{
			if(flag1[b[x][i]]) dfs(b[x][i],1-flag);
		}
	}
}
int main()
{
	int n,m,i,j,k;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++) 
		{
			a[i].clear(),b[i].clear();
			flag1[i]=flag2[i]=1;
			for(j=0;j<=n;j++) dp[i][j]=0;
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			b[j].push_back(i);
		}
		dp[0][0]=1;
		cnt1=cnt2=0;
		for(i=1;i<=n;i++)
		{
			if(a[i].size()==0)
			{
				flag1[i]=0;
				cnt1++;
			}
			if(b[i].size()==0)
			{
				flag2[i]=0;
				cnt2++;
			}
		}
		for(i=0;i<=cnt1;i++)
		{
			for(j=0;j<=cnt2;j++) dp[i][j]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(flag1[i]) 
			{
				cnt1=cnt2=0;
				dfs(i,0);
				for(j=n/2;j>=0;j--)
				{
					for(k=n/2;k>=0;k--)
					{
						if(dp[j][k])
							dp[j+cnt1][k+cnt2]=1;
					}
				}
			}
		}
		for(i=n/2;i>=0;i--)
		{
			if(dp[i][i]) break;
		}
		printf("%d\n",i);
	}
	return 0;
}