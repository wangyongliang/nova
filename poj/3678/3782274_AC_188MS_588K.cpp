#include<stdio.h>
#include<vector>
using namespace std;
vector<int> a[2200],b[2100];
int n;
int flag[2200],flg[2200];
int st,q[2200];
void dfs1(int x)
{
	int i;
	flg[x]=1;
	for(i=0;i<a[x].size();i++)
	{
		if(flg[a[x][i]]==0)
		{
			dfs1(a[x][i]);
		}
	}
	q[st++]=x;
}
int p[2200],pp;
void dfs2(int x)
{
	flg[x]=2;
	int i;
	for(i=0;i<b[x].size();i++)
	{
		if(flg[b[x][i]]==1)
		{
			dfs2(b[x][i]);
		}
	}
	p[pp++]=x;
}
int find(int x)
{
	if(x==flag[x]) return x;
	else
	{
		int y=find(flag[x]);
		flag[x]=y;
		return y;
	}
}
void scc()
{
	int i;
	int x,y;
	for(i=0;i<n*2;i++)
	{
		if(flg[i]==0)
		{
			st=0;
			dfs1(i);
			for(st--;st>=0;st--)
			{
				if(flg[q[st]]==1)
				{
					pp=0;
					dfs2(q[st]);
					x=find(p[pp-1]);
					for(pp-=2;pp>=0;pp--)
					{
						y=find(p[pp]);
						flag[y]=x;
					}
				}
			}
		}
	}
	for(i=0;i<2*n;i++) x=find(i);
}
int main()
{
	int m,i,j,c;
	char s[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<2*n;i++) a[i].clear(),b[i].clear();
		while(m--)
		{
			scanf("%d%d%d%s",&i,&j,&c,s);
			if(strcmp(s,"AND")==0)
			{
				if(c==1)
				{
					a[i+n].push_back(i);
					a[j+n].push_back(j);
				}
				else
				{
					a[i].push_back(j+n);
					a[j].push_back(i+n);
				}
			}
			else if(strcmp(s,"OR")==0)
			{
				if(c==1)
				{
					a[i+n].push_back(j);
					a[j+n].push_back(i);
				}
				else
				{
					a[i].push_back(i+n);
					a[j].push_back(j+n);
				}
			}
			else
			{
				if(c)
				{
					a[i].push_back(j+n);
					a[i+n].push_back(j);
					a[j].push_back(i+n);
					a[j+n].push_back(i);
				}
				else
				{
					a[i].push_back(j);
					a[j].push_back(j);
					a[i+n].push_back(j+n);
					a[j+n].push_back(i+n);
				}
			}
		}
		for(i=0;i<n*2;i++)
		{
			flag[i]=i;
			flg[i]=0;
			for(j=0;j<a[i].size();j++)
			{
				b[a[i][j]].push_back(i);
			}
		}
		scc();
		for(i=0;i<n;i++)
		{
			if(flag[i]==flag[i+n]) break;
		}
		if(i==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
