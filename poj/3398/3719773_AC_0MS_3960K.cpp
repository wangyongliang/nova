#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 100010
int flag[maxn];
vector<int> a[maxn],b[maxn];

int n;
int dp[maxn][3];


int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}

void dfs(int x)
{
	int i;

	if(flag[x]) return ;
	flag[x]=1;
	a[x].clear();
	for(i=0;i<b[x].size();i++)
	{
		if(flag[b[x][i]]==0)
		{
			a[x].push_back(b[x][i]);
			dfs(b[x][i]);
		}
	}
}

//dp[x][0] 没有放看得见
//dp[x][1] 放了
//dp[x][2] //看不见
void f(int x)
{
	if(flag[x]) return ;
	flag[x]=1;
	int i;
	if(a[x].size()==0)
	{
		dp[x][1]=1;
		dp[x][0]=10000000;
		dp[x][2]=0;
		return ;
	}
	
	for(i=0;i<a[x].size();i++) f(a[x][i]);
	dp[x][1]=1;
	dp[x][2]=0;
	dp[x][0]=1000000;
	int sum=0;
	for(i=0;i<a[x].size();i++) 
	{
	//	printf("%d\n",a[x][i]);
		dp[x][1]+=min(dp[a[x][i]][2],dp[a[x][i]][1]);
		dp[x][2]+=dp[a[x][i]][0];
	}
	int tp;
	sum=dp[x][2];
	for(i=0;i<a[x].size();i++)
	{
	//	printf("%d %d %d\n",a[x][i],dp[a[x][i]][0],dp[a[x][i]][1]);
	//	if(dp[a[x][i]][1]==min(dp[a[x][i]][0], dp[a[x][i]][1])) tp=sum;
	//	else tp=sum-dp[a[x][i]][0]+dp[a[x][i]][1];
		tp=sum-dp[a[x][i]][0]+dp[a[x][i]][1];
		dp[x][0]=min(dp[x][0],tp);
	}

}
int main()
{
	int i,j;
	int x,y;
	int first=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		for(i=1;i<=n;i++)
		{
			b[i].clear(),a[i].clear();
			flag[i]=0;
		}
		for(i=0;i<n-1;i++) 
		{
			scanf("%d%d",&x,&y);
			b[x].push_back(y);
			b[y].push_back(x);
		}
		scanf("%d",&first);
		for(i=1;i<=n;i++)
		{
			if(flag[i]==0) 
			{
				dfs(i);
			}
	//		for(j=0;j<a[i].size();j++) printf("%d ",a[i][j]);
	//		printf("\n");
		}	
		for(i=1;i<=n;i++) flag[i]=0;
		f(1);
		printf("%d\n",min(dp[1][0],dp[1][1]));
		if(first==-1) break;
	}
	return 0;
}
