#include<stdio.h>
#define maxn 1000000
struct node
{
	int min,max,l,r;
	int cnt,col;
}a[maxn];
void build(int min,int max,int n)
{
	a[n].r=a[n].min=min;
	a[n].l=a[n].max=max;
	a[n].cnt=max-min+1;
	a[n].col=-1;
	if(min<max) 
	{
		int mid=(min+max)/2;
		build(min,mid,n*2);
		build(mid+1,max,n*2+1);
	}
}
void insert(int min,int max,int n,int col)
{
	if(min<=a[n].min&&max>=a[n].max)
	{
		a[n].cnt=(a[n].max-a[n].min+1)*col;
		a[n].col=col;
		if(col) a[n].l=a[n].max,a[n].r=a[n].min;
		else a[n].l=a[n].min-1,a[n].r=a[n].max+1;
	}
	else
	{
		int mid=(a[n].min+a[n].max)/2;
		if(a[n].col!=-1)
		{
			insert(a[n].min,a[n].max,n*2,a[n].col);
			insert(a[n].min,a[n].max,n*2+1,a[n].col);
			a[n].col=-1;
		}
		if(min<=mid) insert(min,max,n*2,col);
		if(max>mid) insert(min,max,n*2+1,col);
		if(a[n*2].l==a[n*2].max) a[n].l=a[n*2+1].l;
		else	a[n].l=a[n*2].l;
		if(a[n*2+1].r==a[n*2+1].min) a[n].r=a[n*2].r;
		else	a[n].r=a[n*2+1].r;
		a[n].cnt=a[n*2+1].l-a[n*2].r+1;
		if(a[n].cnt<a[n*2].cnt) a[n].cnt=a[n*2].cnt;
		if(a[n].cnt<a[n*2+1].cnt) a[n].cnt=a[n*2+1].cnt;
	}
}
int find(int d,int n)
{
	if(d>a[n].cnt) return 0;
	if(a[n].min==a[n].max) return a[n].min;
	else
	{
		int mid=(a[n].min+a[n].max)/2;
		if(a[n].col!=-1)
		{
			insert(a[n].min,a[n].max,n*2,a[n].col);
			insert(a[n].min,a[n].max,n*2+1,a[n].col);
			a[n].col=-1;
		}
		if(a[n*2].cnt>=d) return find(d,n*2);
		int tp=a[n*2+1].l-a[n*2].r+1;
		if(tp>=d) return a[n*2].r;
		return find(d,n*2+1);
	}
}
int main()
{
	int m,n,i,j;
//	freopen("hotel.12.in","r",stdin);
//	freopen("1.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		build(1,n,1);
		while(m--)
		{
			scanf("%d",&n);
			if(n==1) 
			{
				scanf("%d",&i);
				j=find(i,1);
				printf("%d\n",j);
				if(j)	insert(j,j+i-1,1,0);
			}
			else 
			{
				scanf("%d%d",&i,&j);
				insert(i,i+j-1,1,1);
			}
		}
	}
	return 0;
}