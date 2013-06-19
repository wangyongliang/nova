//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//pku 3293
#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 1000000
struct node
{
	int x,y;
	__int64 sum;
	__int64 cov;
} a[maxn*2+100];
int b[maxn];
void build(int x,int y,int fa)
{
	a[fa].x=x;
	a[fa].y=y;
	a[fa].cov=0;
	int mid=(x+y)/2;
	if(x==y)
	{
		a[fa].sum=b[x];
		a[fa].cov=0;
	}
	else
	{
		build(x,mid,fa*2);
		build(mid+1,y,fa*2+1);
		a[fa].sum=a[fa*2].sum+a[fa*2+1].sum;
		a[fa].cov=0;
	}
}
void insert(int x,int y,int fa,__int64 k)
{
	__int64 cnt;
	int min,max;
	min=x>a[fa].x?x:a[fa].x;
	max=y<a[fa].y?y:a[fa].y;
	cnt=max-min+1;
	a[fa].sum+=cnt*k;
	if(x<=a[fa].x&&y>=a[fa].y)
	{
		a[fa].cov+=k;
	}
	else
	{
		int mid=(a[fa].x+a[fa].y)/2;
		if(x<=mid) insert(x,y,fa*2,k);
		if(y>mid) insert(x,y,fa*2+1,k);
	}
}
__int64 get(int x,int y,int fa)
{
	__int64 ans;
	__int64 cnt,cov;
	if(x<=a[fa].x&&y>=a[fa].y)
	{
		ans=a[fa].sum;
	}
	else
	{
		if(a[fa].cov!=0)
		{
			insert(a[fa].x,a[fa].y,fa*2,a[fa].cov);
			insert(a[fa].x,a[fa].y,fa*2+1,a[fa].cov);
			a[fa].cov=0;
		}
		int mid=(a[fa].x+a[fa].y)/2;
		ans=0;
		if(x<=mid) ans+=get(x,y,fa*2);
		if(y>mid) ans+=get(x,y,fa*2+1);
	}
	return ans;
}
int main()
{
	int n,q,i,j;
	__int64 k;
	char s[10];
	__int64 ans;
	scanf("%d%d",&n,&q);
//	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		build(1,n,1);
		while(q--)
		{
			scanf("%s",s);
			if(s[0]=='C')
			{
				scanf("%d%d%I64d",&i,&j,&k);
				if(i>j) swap(i,j);
				insert(i,j,1,k);
			}
			else
			{
				scanf("%d%d",&i,&j);
				if(i>j) swap(i,j);
				ans=get(i,j,1);
				printf("%I64d\n",ans);
			}
		}
	}
	return 0;
}