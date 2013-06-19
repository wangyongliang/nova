#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 1700
vector<int> a[maxn],b[maxn];
int n,cnt[maxn];
int flag[maxn];
int q[maxn],qq,p[maxn],pp;
int sum[maxn];
void dfs1(int x)
{
	int i;
	flag[x]=1;
	for(i=0;i<a[x].size();i++)
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
	int i;
	flag[x]=2;
	for(i=0;i<b[x].size();i++)
	{
		if(flag[b[x][i]]==1)
		{
			dfs2(b[x][i]);
		}
	}
	p[pp++]=x;
}
int ID[maxn];
int dp[maxn],ans[maxn];
int find(int x)
{
	int y=x,z;
	while(ID[y]!=y) y=ID[y];
	while(ID[x]!=x)
	{
		z=x;
		x=ID[x];
		ID[z]=y;
	}
	return y;
}
void scc()
{
	int i,j,x,y;
	int tp[maxn];
	for(i=1;i<=n;i++)
	{
		flag[i]=0;
		ID[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			qq=0;
			dfs1(i);
			for(j=qq-1;j>=0;j--)
			{
				if(flag[q[j]]==1)
				{
					pp=0;
					dfs2(q[j]);
					x=find(p[pp-1]);
					for(pp-=2;pp>=0;pp--)
					{
						y=find(p[pp]);
						ID[y]=x;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++) 
	{
		x=find(i);
		b[i].clear();
		tp[i]=0;
		flag[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		x=ID[i];
		tp[x]+=sum[i];
		flag[x]=1;
		for(j=0;j<a[i].size();j++)
		{
			y=ID[a[i][j]];
			if(x!=y)	b[x].push_back(y);
		}
	}
	for(i=1;i<=n;i++) sum[i]=tp[i];
}
int f()
{
	int i,j;
	for(i=1;i<=n;i++) cnt[i]=0;
	for(i=1;i<=n;i++)
	{
		if(flag[i])
		{
			for(j=0;j<b[i].size();j++)
			{
				cnt[b[i][j]]++;
			}
			dp[i]=-100000000;
		}
	}
	int st,en;
	en=0;
//	for(i=1;i<=n;i++) printf("%d %d\n",flag[i],b[i].size());
//	printf("\n");
	for(i=1;i<=n;i++)
	{
		if(flag[i])
		{
			if(cnt[i]==0)
			{
				q[en++]=i;
			}
		}
	}
	dp[1]=sum[1];
	q[0]=1;
	st=0;
	int x,y;
	while(st<en)
	{
		x=q[st];
		for(i=0;i<b[x].size();i++)
		{
			y=b[x][i];
			cnt[y]--;
			if(dp[y]<dp[x]+sum[y]) dp[y]=dp[x]+sum[y];
			if(cnt[y]==0) q[en++]=y;
		}
		st++;
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(flag[i])
		{
			if(ans<dp[i]) ans=dp[i];
		}
	}
	return ans;
}
int index[60][60];
char s[100][100];
int main()
{
	int r,c;
	int t,i,j,k;
	scanf("%d",&t);
	int x,y;
	while(t--)
	{
		scanf("%d%d",&r,&c);
		k=1;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++) index[i][j]=k++;
		}
		n=k-1;
		for(i=0;i<maxn;i++) 
		{
			a[i].clear();
			b[i].clear();
		}
		for(i=0;i<r;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<r;i++)
		{
			
			for(j=0;j<c;j++)
			{
				if((s[i][j]>='0'&&s[i][j]<='9')||s[i][j]=='*')
				{
					if(i+1<r&&s[i+1][j]!='#') 
					{
						a[index[i][j]].push_back(index[i+1][j]);
						b[index[i+1][j]].push_back(index[i][j]);
					}
					if(j+1<c&&s[i][j+1]!='#')
					{
						a[index[i][j]].push_back(index[i][j+1]);
						b[index[i][j+1]].push_back(index[i][j]);
					}
				}
				if(s[i][j]>='0'&&s[i][j]<='9') 
				{
					sum[index[i][j]]=s[i][j]-'0';
				}
				else if(s[i][j]=='*')
				{
					scanf("%d%d",&x,&y); 
					sum[index[i][j]]=0;
					if(s[x][y]!='#')
					{
						a[index[i][j]].push_back(index[x][y]);
						b[index[x][y]].push_back(index[i][j]);
					}
				}
				else sum[index[i][j]]=0;
			}
		}
		scc();
		printf("%d\n",f());
	}
	return 0;
}


