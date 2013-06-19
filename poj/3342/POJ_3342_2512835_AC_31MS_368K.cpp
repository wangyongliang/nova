#include<stdio.h>
#include<memory.h>
#include<string>
#include<map>
using namespace std;
#define size 220
struct node
{
	int yes, no;
	int flagyes, flagno;
}dp[size];
map<string,int> f;
int g[size][size],idx[size];
int max(int a, int b)
{
	return a > b ? a : b;
}
void dfs(int k, int root)
{
	int i, t;
	if(idx[k] == 1 && k != 1)
	{
		dp[k].yes = 1;
		dp[k].no = 0;
		dp[k].flagyes = dp[k].flagno = 0;
		return;
	}
	for(i = 0; i < idx[k]; i++)
	{
		t = g[k][i];
		if(t == root) continue;
		dfs(t, k);
	}
	dp[k].yes = 1;
	dp[k].no = 0;
	dp[k].flagyes = dp[k].flagno = 0;

	for(i = 0; i < idx[k]; i++)
	{
		t = g[k][i];
		if(t == root) continue;

		dp[k].yes += dp[t].no;
		if(dp[t].flagno == 1) dp[k].flagyes = 1; 

		if(dp[t].yes > dp[t].no)
		{
			dp[k].no += dp[t].yes;
			if(dp[t].flagyes == 1) dp[k].flagno = 1;
		}
		else if(dp[t].yes == dp[t].no)
		{
			dp[k].no += dp[t].yes;
			dp[k].flagno = 1;
		}
		else
		{
			dp[k].no += dp[t].no;
			if(dp[t].flagno == 1) dp[k].flagno = 1;
		}
	}
}
main()
{
	int i, j, T;
	int x, y, t, ans, n;
	char s1[25],s2[25];
	while(1)
	{
		scanf("%d",&n);
		if(n == 0) break;
		memset(idx,0,sizeof(idx));
		memset(g,0,sizeof(g));
		memset(dp,0,sizeof(dp));
		f.clear();
		t = 1;
		scanf("%s",s1);
		f[s1] = t++;
		for(i = 1; i < n; i++)
		{
			scanf("%s%s",s1, s2);
			if(!f[s1]) f[s1] = t++;
			if(!f[s2]) f[s2] = t++;
			g[f[s1]][idx[f[s1]]++] = f[s2];
			g[f[s2]][idx[f[s2]]++] = f[s1];
		}
		dfs(1,0);
		if(dp[1].yes > dp[1].no)
		{
			printf("%d ",dp[1].yes);
			if(dp[1].flagyes)
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n");
			}
		}
		else if(dp[1].yes == dp[1].no)
		{
			printf("%d No\n",dp[1].yes);
		}
		else
		{
			printf("%d ",dp[1].no);
			if(dp[1].flagno)
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n");
			}
		}		
	}
	return 0;
}
