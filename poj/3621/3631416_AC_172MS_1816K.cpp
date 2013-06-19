#include<stdio.h>
#include<vector>
#include<queue>
#define maxn 1011
using namespace std;
struct node
{
	int x,len;
};
vector<node> a[maxn];
int cnt[maxn],q[maxn*maxn],f[maxn],n,m;
bool flg[maxn];
double dis[maxn];
int ck(double mid)
{
	int i,x,y;
	for(i=1;i<=n;i++) 
	{
		dis[i]=0.0,q[i]=i;
		flg[i]=1;
		cnt[i]=0;
	}
	int st=1,en=n+1;
	while(st<en)
	{
		x=q[st++];
		flg[x]=0;
		for(i=0;i<a[x].size();i++)
		{
			y=a[x][i].x;
			double tp=f[y]-a[x][i].len*mid;
			if(dis[y]<dis[x]+tp)
			{
				cnt[y]=cnt[x]+1;
				if(cnt[y]>n) return 1;
				dis[y]=dis[x]+tp;
				if(flg[y]==0) flg[y]=1,q[en++]=y;
			}
		}
	}
	return 0;
}
int main()
{
	int i,j;
	node tp;
	double min, max,mid;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
				min=1e20;
		max=0.0;
		for(i=1;i<=n;i++)
		{
			a[i].clear();
			scanf("%d",&f[i]);
			min=min>f[i]?f[i]:min;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&j,&tp.x,&tp.len);
			a[j].push_back(tp);
			max=max<tp.len?tp.len:max;
		}
		//max=max/min;
		max=1000;
		min=0.0;
		while(max-min>1e-4)
		{
			mid=(min+max)/2.0;
			if(ck(mid)) min=mid;
			else max=mid;
		}
	//	min=1.0/min;
		printf("%.2lf\n",min);
	}
	return 0;
}
