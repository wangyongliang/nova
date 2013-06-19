/*
ID: 05272021
LANG: C++
PROG:
*/
/*crackerwang*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define ABS(X)  (x)>0?(x):-(x)
#define ps system("pause")
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)

int dp[2010][2010];
int a[300];
int d[300];
char str[30000];
int dfs(int x,int y)
{
	if(x>y) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	if(x==y)
	{
		dp[x][y]=0;
	}
	else
	{
		dp[x][y]=2000000000;
		if(str[x]==str[y]) dp[x][y]=MIN(dp[x][y],dfs(x+1,y-1));
		dp[x][y]=MIN(dp[x][y],dfs(x+1,y)+a[str[x]]);
		dp[x][y]=MIN(dp[x][y],dfs(x+1,y)+d[str[x]]);
		
		dp[x][y]=MIN(dp[x][y],dfs(x,y-1)+a[str[y]]);
		dp[x][y]=MIN(dp[x][y],dfs(x,y-1)+d[str[y]]);
		
	}
	return dp[x][y];
}
int main()
{
	int n,m;
	int i,j;
	char ch[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		scanf("%s",str)		;
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++) dp[i][j]=-1;
		}
		for(i=0;i<n;i++)
		{
			int x,y;
			scanf("%s%d%d",ch,&x,&y);
			a[ch[0]]=x;
			d[ch[0]]=y;
		}
		printf("%d\n",dfs(0,m-1));
	/*	for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++) printf("%d ",dp[i][j]);
			printf("\n");
		}
		*/
		
		
	}
	return 0;
}
