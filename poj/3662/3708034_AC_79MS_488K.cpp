#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int x;
	int l;
};
#define maxn 1010
vector<node> a[maxn];
struct cmp
{
	bool operator()(const node &x,const node &y)
	{
		if(x.l==y.l) return x.x<y.x;
		else return x.l>y.l;
	}
};
priority_queue<node,vector<node>,cmp> heap;
int dis[maxn];
int n;
int inf =10000000;
int dij(int mid)
{
	int i,j;
	while(heap.size()) heap.pop();
	for(i=0;i<=n;i++) dis[i]=10000000;
	dis[1]=0;
	node tp;
	tp.x=1;
	tp.l=0;
	heap.push(tp);
	while(heap.size())
	{
		tp=heap.top();
		heap.pop();
		int x=tp.x;
		if(x==n) break;
		if(dis[tp.x]<tp.l) continue;
		node tp1;
		for(i=0;i<a[x].size();i++)
		{
			int y=a[x][i].x;
			if(dis[y]>dis[x]+(a[x][i].l>mid))
			{
				dis[y]=dis[x]+(a[x][i].l>mid);
				tp1.x=y;
				tp1.l=dis[y];
				heap.push(tp1);
			}
		}
	}
	return dis[n];
}
int main()
{
	int p,k;
	node tp;
	int i,j;
	int min,max,mid;
	while(scanf("%d%d%d",&n,&p,&k)!=EOF)
	{
		for(i=0;i<=n;i++) a[i].clear();
		while(p--)
		{
			scanf("%d%d%d",&i,&j,&tp.l);
			tp.x=i;
			a[j].push_back(tp);
			tp.x=j;
			a[i].push_back(tp);
		}
		min=0;
		max=1000010;
		while(max>min)
		{
			mid=(min+max)/2;
			i=dij(mid);
			if(i>k) min=mid+1;
			else max=mid;
		}
		if(min<1000010)	printf("%d\n",min);
		else printf("-1\n");
	}
	return 0;
}