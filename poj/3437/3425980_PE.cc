#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
char s[10000];
vector<int> a[10000];
int dp[10000];
int m;
int len;
int dfs(int n,int k,int deep)
{
	int i;
	dp[n]=deep;
	for(i=k;i<len;i++)
	{
		if(s[i]=='u') return i;
		else
		{
			a[n].push_back(m+1);
			m++;
			i=dfs(m,i+1,deep+1);
		}
	}
}
void f(int n,int k,int deep)
{
	dp[n]=deep;
	int i;
	if(a[n].size())
	{
		i=a[n].front();
		a[n].erase(a[n].begin());
		f(i,n,deep+1);
	}
		if(k>=0&&a[k].size())
		{
			i=a[k].front();
			a[k].erase(a[k].begin());
			f(i,k,deep+1);
		}
}
int main()
{
	int i,j;
	int t=1;
	int max;
	while(scanf("%s",s))
	{
		if(s[0]=='#') break;
		for(i=0;i<1000;i++) a[i].clear();
		max=0;
		printf("Tree %d:",t++);
		len=strlen(s);
		m=0;
		dfs(0,0,0);
		max=0;
		for(i=0;i<=m;i++) max=max<dp[i]?dp[i]:max;
		printf(" %d=>",max);
		f(0,-1,0);
		max=0;
		for(i=0;i<=m;i++) max=max<dp[i]?dp[i]:max;
		printf(" %d\n",max);
	}
	return 0;
}