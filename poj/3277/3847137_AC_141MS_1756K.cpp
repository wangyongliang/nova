#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,h;
}a[50000];
struct nde
{
	int x,y;
};
bool cp(const node &x,const node &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
struct cmp
{
	bool operator ()(const nde &x,const nde &y)
	{
		return x.x<y.x;
	}
};
priority_queue<nde,vector<nde>,cmp> heap;
int cnt[110000],dp[110000];
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		j=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
			cnt[j++]=a[i].x;
			cnt[j++]=a[i].y;
		}
		int m=j;
		sort(cnt,cnt+m);
		sort(a,a+n,cp);
		j=0;
		nde tp;
		while(heap.size()) heap.pop();
		for(i=0;i<m;i++)
		{
			dp[i]=0;
			for(;j<n&&a[j].x<cnt[i];j++)
			{
				if(a[j].y>=cnt[i])
				{
					tp.x=a[j].h;
					tp.y=a[j].y;
					heap.push(tp);
				}
			}
			while(heap.size())
			{
				tp=heap.top();
				if(tp.y>=cnt[i])  break;
				heap.pop();
			}
			if(heap.size())	dp[i]=heap.top().x;
		}
		__int64 ans=0,tpp;
		for(i=1;i<m;i++)
		{
			tpp=dp[i];
			tpp*=(cnt[i]-cnt[i-1]);
			ans+=tpp;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}