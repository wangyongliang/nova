#include<stdio.h>
#include<vector>
using namespace std;
#define size  1009
int n,m;
struct  node
{
	int i;
	int a;
};
vector<node> mp[size];
vector<node>::iterator it;
int dij()
{
	int i,k,max,maxx,min;
	int close[size]={0};
	k=n-1;
	for(it=mp[1].begin();it!=mp[1].end();it++)
	{
		close[it->i]=it->a;
	}
	close[1]=-1;
	while(k--)
	{
		for(i=1;close[i]==-1&&i<=n;i++);
		max=i;
		for(;i<=n;i++) max=close[i]>close[max]?i:max;
		if(max==n) return close[max];
		maxx=close[max];
		close[max]=-1;
		for(it=mp[max].begin();it!=mp[max].end();it++)
		{
			min=maxx>it->a?it->a:maxx;
			if(close[it->i]!=-1&&min>close[it->i]) close[it->i]=min;
		}
	}
}
int main()
{
	node q;
	int i,t,k=1;
	int x ,y,c;
	scanf("%d",&t);
	while(k<=t)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) mp[i].clear();
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&c);
			q.a=c;
			q.i=x;
			mp[y].push_back(q);
			q.i=y;
			mp[x].push_back(q);
		}
		printf("Scenario #%d:\n%d\n\n",k,dij());
		k++;
	}
	return 0;
}
