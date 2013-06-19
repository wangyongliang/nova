#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 1000000+10
struct node
{
	int x,sum,y;
}a[maxn*2+100];
struct Q
{
	int x,y,rank,k;
}q[maxn/2];
int n;
int b[maxn];
int c[maxn];
bool cmp(const int &x,const int &y)
{
	return b[x]<b[y];
}
bool cmp1(const Q &x,const Q &y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
void build(int x,int y,int fa)
{
	a[fa].x=x;
	a[fa].y=y;
	a[fa].sum=0;
	if(x==y) return;
	build(x,(x+y)/2,fa*2);
	build((x+y)/2+1,y,fa*2+1);
}
void insert(int k,int fa,int flag)
{
	int mid=(a[fa].x+a[fa].y)/2;
	a[fa].sum+=flag;
	if(a[fa].x==a[fa].y) return;
	else
	{
		if(k<=mid) insert(k,fa*2,flag);
		if(k>mid) insert(k,fa*2+1,flag);
	}
}
int get(int k,int fa)
{
	if(a[fa].x==a[fa].y) return a[fa].x;
	else
	{
		if(k<=a[fa*2].sum) return get(k,fa*2);
		if(k>a[fa*2].sum) return get(k-a[fa*2].sum,fa*2+1);
	}
}
int ans[maxn/2];
int main()
{
	int i,j;
	int m;
	int min,max;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			c[i]=i;
		}
		sort(c,c+n,cmp);
		for(i=0;i<n;i++)
		{
			j=b[c[i]];
			b[c[i]]=i;
			c[i]=j;
		}
		build(0,n,1);
		for(i=0;i<m;i++) 
		{
			scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].k);
			q[i].x--;
			q[i].y--;
			q[i].rank=i;
		}
		sort(q,q+m,cmp1);
		for(i=q[0].x;i<=q[0].y;i++) insert(b[i],1,1);
		j=get(q[0].k,1);
		ans[q[0].rank]=c[j];
		for(i=1;i<m;i++)
		{
			min=q[i].x>q[i-1].y+1?q[i-1].y+1:q[i].x;
			for(j=q[i-1].x;j<min;j++) insert(b[j],1,-1);
			max=q[i].x<q[i-1].y+1?q[i-1].y+1:q[i].x;
			for(j=max;j<=q[i].y;j++) insert(b[j],1,1);
			j=get(q[i].k,1);
			ans[q[i].rank]=c[j];
		}
		for(i=0;i<m;i++) printf("%d\n",ans[i]);
	}
	return 0;
}