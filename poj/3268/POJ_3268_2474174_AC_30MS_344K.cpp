#include<stdio.h>
#include<vector>
#define size 1009
#define inf 9999999
using namespace std;
struct node
{
	int i;
	int len;
};
int n,m;
int a[size];
vector<node> mp[size];
vector<node> mmp[size];
vector<node>::iterator it;
void dij(int k)
{
	int close[size];
	int i,min,temp;
	int sum=0;
	temp=n;
	for(i=1;i<=n;i++) close[i]=inf;
	for(it=mp[k].begin();it!=mp[k].end();it++)
	{
		close[it->i]=it->len;
	}
	close[k]=-1;
	temp--;
	while(temp--)
	{
		for(i=1;i<=n&&close[i]==-1;i++) ;
		min=i;
		for(;i<=n;i++)
		{
			if(close[i]!=-1)
				min=close[min]>close[i]?i:min;
		}
		if(close[min]==-1||min>n) break;
		a[min]=close[min];
		close[min]=-1;
		for(it=mp[min].begin();it!=mp[min].end();it++)
		{
			if(close[it->i]!=-1&&close[it->i]>a[min]+it->len) close[it->i]=a[min]+it->len;
		}
	}
}
void dij1(int k)
{
	int close[size];
	int i,min,temp;
	int sum=0;
	temp=n;
	for(i=1;i<=n;i++) close[i]=inf;
	for(it=mmp[k].begin();it!=mmp[k].end();it++)
	{
		close[it->i]=it->len;
	}
	close[k]=-1;
	temp--;
	while(temp--)
	{
		for(i=1;i<=n&&close[i]==-1;i++) ;
		min=i;
		for(;i<=n;i++)
		{
			if(close[i]!=-1)
				min=close[min]>close[i]?i:min;
		}
		if(close[min]==-1||min>n) break;
		a[min]+=close[min];
		for(it=mmp[min].begin();it!=mmp[min].end();it++)
		{
			if(close[it->i]!=-1&&close[it->i]>close[min]+it->len) close[it->i]=close[min]+it->len;
		}
		close[min]=-1;
	}
}
int main()
{
	int x,i;
	int a1,b1,c1;
	int max;
	node q;
	while(scanf("%d%d%d",&n,&m,&x)!=EOF)
	{
		for(i = 1; i <=n; i++)
		{
			mp[i].clear();
			mmp[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a1,&b1,&c1);
				q.i=b1;
				q.len=c1;
				mp[a1].push_back(q);
				q.i=a1;
				mmp[b1].push_back(q);
		
		}
		dij(x);
		dij1(x);
		max=-1;
		for(i=1;i<=n;i++) max=max<a[i]?a[i]:max;
		printf("%d\n",max);
	}
	return 0;
}