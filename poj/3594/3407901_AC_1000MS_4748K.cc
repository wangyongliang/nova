#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int x,s,e,t;
};
bool operator <(const node &x,const node &y)
{
	if(x.t==y.t)
	{
		if(x.x==y.x)
		{
			if(x.s==y.s) return x.e>y.e;
			return x.s>y.s;
		}
		return x.x>y.x;
	}
	return x.t>y.t;
}
priority_queue<node> heap;
vector<node> a[1000];
int dp[110][10010],n;
int inf=0x7fffffff;
void dij(int s,int max)
{
	int i,j,t;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=max;j++) dp[i][j]=inf;
	}
	node tp;
	while(heap.size()) heap.pop();
	for(j=0;j<=max;j++)
	{
		dp[s][j]=0;
		tp.x=s;
		tp.s=j;
		tp.t=0;
		tp.e=0;
		heap.push(tp);
	}
	int x,y,min;
	node tp1;
	while(heap.size())
	{
		tp=heap.top();
		heap.pop();
		x=tp.x;
		s=tp.s;
		t=tp.t;
	//	if(t>dp[x][s]) continue;
		for(i=0;i<a[x].size();i++)
		{
			y=a[x][i].x;
			if(s<a[x][i].s) min=a[x][i].s;
			else min=s;
			if(min+a[x][i].t<=a[x][i].e&&t+a[x][i].t+min-s<dp[y][min+a[x][i].t])
			{
				dp[y][min+a[x][i].t]=t+a[x][i].t+min-s;
				tp1.x=y;
				tp1.e=0;
				tp1.t=dp[y][min+a[x][i].t];
				tp1.s=min+a[x][i].t;
				heap.push(tp1);
			}
		}
	}
}
int main()
{
	int m,s,t,i,j;
	int max;
	while(scanf("%d%d%d%d",&n,&m,&s,&t)!=EOF)
	{
		for(i=0;i<=n;i++) a[i].clear();
		node tp;
		max=0;
		while(m--)
		{
			scanf("%d%d%d%d%d",&i,&tp.x,&tp.s,&tp.e,&tp.t);
			if(max<tp.s) max=tp.s;
			if(max<tp.e) max=tp.e;
			a[i].push_back(tp);
		}
		dij(s,max);
		int ans=inf;
		for(i=0;i<=max;i++)
		{
			if(ans>dp[t][i]) ans=dp[t][i];
		}
		if(ans==inf) printf("Impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}