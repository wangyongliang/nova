#include<iostream>
#include<vector>
using namespace std;
#define maxn 10000
vector<int> a[maxn],b[maxn];
int flag[maxn];
int q[maxn],qq,p[maxn],pp;
int n,m;
void dfs1(int x)
{
	flag[x]=1;
	for(int i=0;i<a[x].size();i++)
	{
		if(flag[a[x][i]]==0)
		{
			dfs1(a[x][i]);
		}
	}
	q[qq++]=x;

}
void dfs2(int x)
{
	flag[x]=2;
	for(int i=0;i<b[x].size();i++)
	{
		if(flag[b[x][i]]==1)
		{
			dfs2(b[x][i]);
		}
	}
	p[pp++]=x;
}
int c[maxn];
int find(int x)
{
	int y=x;
	while(c[x]!=x) x=c[x];
	while(y!=x)
	{
		int tp=c[y];
		c[y]=x;
		y=tp;
	}
	return x;
}
void scc()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		flag[i]=0;
		c[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			qq=0;
			dfs1(i);
			for(;qq;qq--)
			{
				if(flag[q[qq-1]]==1)
				{
					pp=0;
					dfs2(q[qq-1]);
					find(p[pp-1]);
					for(j=0;j<pp-1;j++) 
					{
						int x=find(p[j]);
						c[x]=c[p[pp-1]];
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++) find(i);
}
int cnt[maxn];
int  check()
{
	int i,j;
	scc();
	for(i=1;i<=n;i++) 
	{
		b[i].clear(),cnt[i]=0;
		flag[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		flag[c[i]]=1;
		for(j=0;j<a[i].size();j++)
		{
			if(c[i]==c[a[i][j]]) continue;
			b[c[i]].push_back(c[a[i][j]]);
			cnt[c[a[i][j]]]++;
		//	flag[c[i]]=flag[c[a[i][j]]]=1;
		}
	}
	int ct,ct1;
	while(1)
	{
		ct1=ct=0;
		int x;
		for(i=1;i<=n;i++)
		{
			if(flag[i]&&cnt[i]==0) {ct++;
			x=i;
			}
			ct1+=flag[i];
		}
		if(ct1==0) break;
		if(ct>1) return 0;
		if(ct==0) while(1);
		for(i=0;i<b[x].size();i++)
		{
			cnt[b[x][i]]--;
		}
		flag[x]=0;
	}
	return 1;

}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			a[i].clear();
			b[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			if(i==j) continue;
			a[i].push_back(j);
			b[j].push_back(i);
		}
		if(check()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
