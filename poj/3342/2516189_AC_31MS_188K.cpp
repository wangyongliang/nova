#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#define size 220
using namespace std;
struct p
{
	int i;
};
struct node
{
	int flagyes,flagno;
	int yes,no;
}dp[size];
vector <p> a[size];
map <string,int> mp;
void dfs(int k)
{
	vector<p>::iterator itt;
	itt=a[k].begin();
	
	if(itt==a[k].end())
	{
		dp[k].flagyes=dp[k].flagno=0;
		dp[k].yes=1;
		dp[k].no=0;
		return ;
	}
	for(itt=a[k].begin();itt!=a[k].end();itt++) 
		dfs(itt->i);
	dp[k].yes=1;
	dp[k].no=0;
	dp[k].flagno=dp[k].flagyes=0;
	for(itt=a[k].begin();itt!=a[k].end();itt++)
	{
		dp[k].yes+=dp[itt->i].no;
		dp[k].flagyes=dp[k].flagyes||dp[itt->i].flagno;
		if(dp[itt->i].no>dp[itt->i].yes)
		{
			dp[k].flagno=dp[k].flagno||dp[itt->i].flagno;
			dp[k].no+=dp[itt->i].no;
		}
		else if(dp[itt->i].no==dp[itt->i].yes)
		{
			dp[k].flagno=1;
			dp[k].no+=dp[itt->i].yes;
		}
		else
		{
			dp[k].flagno=dp[k].flagno||dp[itt->i].flagyes;
			dp[k].no+=dp[itt->i].yes;
		}
	}
}
int main()
{
	vector <p>::iterator it;
	int n;
	int i,t,j;
	p q;
	char s[100],ss[100];
	while(scanf("%d",&n)&&n)
	{
		t=2;
		mp.clear();
		for(i=1;i<=n;i++) a[i].clear();
		scanf("%s",s);
		mp[s]++;
		for(i=1;i<n;i++)
		{
			scanf("%s%s",s,ss);
			if(!mp[s]) mp[s]=t++;
			if(!mp[ss]) mp[ss]=t++;
			q.i=mp[s];
			j=mp[ss];
			a[j].push_back(q);
		}
		dfs(1);
		if(dp[1].yes>dp[1].no)
		{
			printf("%d ",dp[1].yes);
			if(dp[1].flagyes) printf("No\n");
			else printf("Yes\n");
		}
		else if(dp[1].yes==dp[1].no)
			printf("%d No\n",dp[1].yes);
		else
		{
			printf("%d ",dp[1].no);
			if(dp[1].flagno) printf("No\n");
			else printf("Yes\n");
		}
	}
	return 0;
}
