#include<stdio.h>
#define maxn 100010
int a[maxn];
char s[maxn];
int dp[maxn][2];
int n;
int f(int x,int flag)
{
	int i,j;
	if(dp[x][flag]!=-1) return dp[x][flag];
	else
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				int k;
				if(a[x]==0) k=i||j;
				else k=i&&j;
				if(k==flag){ k=f(x*2,i)+f(x*2+1,j);
				if(dp[x][flag]==-1||dp[x][flag]>k) dp[x][flag]=k;}
			}
		}
		return dp[x][flag];
	}
}
int g(int x)
{
	if(x<n)
	{
		if(a[x]) return g(x*2)&&g(x*2+1);
		else return g(x*2)||g(x*2+1);
	}
	else return 0;
}
int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s);
		for(i=1;i<n;i++) scanf("%d",&a[i]),dp[i][0]=dp[i][1]=-1;
		for(i=n;i<2*n;i++) dp[i][0]=0,dp[i][1]=1;
		k=f(1,0)-f(1,1);
		if(k<0) k=-k;
		j=g(1);
		int ans=0;
		if(j==s[0]-'0') ans=0;
		else ans=k;
		for(i=1;s[i];i++) 
		{
			if(s[i]!=s[i-1])
			{
				if(ans==0) ans+=k;
				else ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}