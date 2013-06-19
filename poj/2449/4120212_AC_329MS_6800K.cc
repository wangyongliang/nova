#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	int x,y;
};
vector<node> a[2000],b[2000];
bool flag[2000];
struct cmp
{
	bool operator ()(const node &x,const node &y)
	{
		return x.x>y.x;
	}
};
priority_queue<node ,vector<node>,cmp> heap;

int dis[1200],n;
void clear()
{
	while(heap.size()) heap.pop();
}


void init(int s)
{
	int i;
	for(i=1;i<=n;i++)
	{
		dis[i]=-1;
		flag[i]=0;
	}
	node tp;
	tp.x=0;
	tp.y=s;
	heap.push(tp);
	dis[s]=0;
	while(heap.size())
	{
		tp=heap.top();
		heap.pop();
		int x,y;
		x=tp.y;
		y=tp.x;
		flag[x]=1;
		for(i=0;i<b[x].size();i++)
		{
			if(dis[b[x][i].x]==-1||dis[b[x][i].x]>dis[x]+b[x][i].y)
			{
				dis[b[x][i].x]=dis[x]+b[x][i].y;
				tp.x=dis[b[x][i].x];
				tp.y=b[x][i].x;
				heap.push(tp);
			}
		}
	}
}

struct cp
{
	bool operator ()(const node &x,const node &y)
	{
		return x.x+dis[x.y]>y.x+dis[y.y];
	}
};
priority_queue<node,vector<node>,cp> hp;
int cnt[1100];
int Astar(int s,int t,int k)
{
	int i;
	node tp;
	tp.x=0;
	if(s==t) k++;
	tp.y=s;
	while(hp.size()) hp.pop();
	hp.push(tp);
	for(i=1;i<=n;i++) cnt[i]=0;
	while(hp.size())
	{
		tp=hp.top();
		hp.pop();
		int x=tp.y,y=tp.x;
		cnt[x]++;
		if(x==t&&cnt[t]==k) return y;
		if(cnt[x]>k) continue;
		for(i=0;i<a[x].size();i++)
		{
			tp=a[x][i];
			if(dis[a[x][i].x]>=0&&cnt[a[x][i].x]<k)
			{
				tp.x=y+a[x][i].y;
				tp.y=a[x][i].x;
				hp.push(tp);
			}
		}
	}
	return -1;
}
int main()
{
	int m,s,t,k,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++) a[i].clear(),b[i].clear();
		int x,y;
		node tp;
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&tp.y);
			tp.x=y;
			a[x].push_back(tp);
			tp.x=x;
			b[y].push_back(tp);
		}
		scanf("%d%d%d",&s,&t,&k);
		init(t);
		printf("%d\n",Astar(s,t,k));
	}
	return 0;
}