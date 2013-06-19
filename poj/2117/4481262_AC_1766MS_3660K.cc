#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define maxn 101000
struct node
{
	int x,id;
};
vector<node> a[maxn];
int dfsn[maxn],low[maxn],flag[maxn],top,vis[maxn];
node stack[maxn];
set<int> cnt;
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
void dfs(int n,int fa,int deep,int id)
{
	stack[top].x=n;
	stack[top].id=-1;
	top++;
	if(vis[n]) return;
	dfsn[n]=low[n]=deep;
	vis[n]=1;
	int i;
	for(i=0;i<a[n].size();i++)
	{
		if(a[n][i].x==fa) continue;
		else 
		{	
			node tp=a[n][i];
			if(vis[a[n][i].x]==0)
			{		
				stack[top].x=n;
				stack[top].id=a[n][i].id;
				top++;
				dfs(a[n][i].x,n,deep+1,a[n][i].id);
				if(low[a[n][i].x]>=dfsn[n])
				{
					while(1)
					{
						if(stack[top-1].x==n&&stack[top-1].id==-1) break;
						if(stack[top-1].id>=0)flag[stack[top-1].id]=a[n][i].id;
						top--;
					}
				}
				else	low[n]=min(low[n],low[a[n][i].x]);			
				stack[top].x=n;
				stack[top].id=-1;
				top++;				
			}
			else
			{
				if(dfsn[a[n][i].x]<dfsn[n])
				{
					stack[top].x=n;
					stack[top].id=a[n][i].id;
					top++;
					stack[top].x=n;
					stack[top].id=-1;
					top++;
					low[n]=min(low[n],dfsn[a[n][i].x]);
				}
			}
		}
	}
}
void find(int x)
{
	int y=x;
	while(y!=flag[y]) y=flag[y];
	int tp;
	while(x!=flag[x])
	{
		tp=flag[x];
		flag[x]=y;
		x=tp;
	}
}
int b[maxn];
int main()
{
	int n,m;
	int i,j;
//	freopen("e.in","r",stdin);
//	freopen("j.out","w",stdout);
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<n;i++) 
		{
			a[i].clear();
			flag[i]=i;
			vis[i]=0;
		}
		for(i=0;i<m;i++) flag[i]=i;
		for(int k=0;k<m;k++)
		{
			scanf("%d%d",&i,&j);
			node tp;
			tp.id=k;
			if(i==j) continue;
			tp.x=j;
			a[i].push_back(tp);
			tp.x=i;
			a[j].push_back(tp);
		}
		int ct=0;
		for(i=0;i<n;i++)
		{
			if(vis[i]==0)
			{
				top=0;
				dfs(i,-1,0,-1);
				ct++;
			}
		}
		for(i=0;i<m;i++)
		{
			find(i);
			b[i]=0;
	//	cout<<i<<"  "<<flag[i]<<endl;
		}
		int ans=ct-1;
	//	cout<<ct<<endl;
		for(i=0;i<n;i++)
		{
			cnt.clear();
			
			for(j=0;j<a[i].size();j++)
				cnt.insert(flag[a[i][j].id]);
			{
			//	cout<<i<<" "<<cnt.size()-1<<" "<<ct<<endl;
				if(ans<cnt.size()-1+ct)		ans=cnt.size()-1+ct;
			}

		}
		printf("%d\n",ans);
	}
	return 0;
}
