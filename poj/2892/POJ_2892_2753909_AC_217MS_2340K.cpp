#include<stdio.h>
#define size 1100000
#define inf 110000
struct node
{
	int min,max;
	int x,y;
}a[size];
int q[50000];
int n;
void build(int x,int y,int k)
{
	a[k].x=x;
	a[k].y=y;
	a[k].min=inf;
	a[k].max=0;
	if(y>x)
	{
		build(x,(x+y)/2,k*2);
		build((x+y)/2+1,y,k*2+1);
	}
}
void f(int p,int k)
{
	int mid;
	if(a[k].x<=p&&a[k].y>=p)
	{
		if(a[k].min>p) a[k].min=p;
		if(a[k].max<p) a[k].max=p;
	}
	if(a[k].x<a[k].y)
	{
		mid=(a[k].x+a[k].y)/2;
		if(p<=mid) f(p,k*2);
		else f(p,k*2+1);
	}
}
void ff(int p,int k)
{
	int mid;
	if(a[k].x==a[k].y)
	{
		if(a[k].x==p)
		{a[k].min=n+1;
		a[k].max=0;}
		return;
	}
	mid=(a[k].x+a[k].y)/2;
	if(p<=mid) ff(p,k*2);
	else	ff(p,k*2+1);
	a[k].max=a[k*2].max>a[k*2+1].max?a[k*2].max:a[k*2+1].max;
	a[k].min=a[k*2].min<a[k*2+1].min?a[k*2].min:a[k*2+1].min;
}
int g(int p,int k)
{
	int mid;
	int k1=0,k2=0;
	mid=(a[k].x+a[k].y)/2;
	if(p>=a[k].y) return a[k].max;
	if(p<a[k].x) return 0;
	k1=g(p,k*2);
	if(p>mid) k2=g(p,k*2+1);
	return k1>k2?k1:k2;
}
int h(int p,int k)
{
	int mid;
	int k1,k2;
	mid=(a[k].x+a[k].y)/2;
	k1=k2=inf;
	if(p<=a[k].x) return a[k].min;
	if(p>a[k].y) return inf;
	k1=h(p,k*2+1);
	if(p<=mid) k2=h(p,k*2);
	return k1<k2?k1:k2;
}
int main()
{
	bool flag[50010];
	int i,p,qq;
	int k1,k2;
	char s[10];
	while(scanf("%d%d",&n,&qq)!=EOF)
	{
		for(i=1;i<n+1;i++) flag[i]=0;
		i=0;
		build(0,n+1,1);
		f(0,1);
		f(n+1,1);
		while(qq--)
		{
			scanf("%s",s);
			if(s[0]=='D') 
			{
				scanf("%d",&p);
				flag[p]=1;
				f(p,1);
				q[i++]=p;
			}
			else if(s[0]=='Q')
			{
				scanf("%d",&p);
				if(flag[p]) printf("0\n");
				else
				{
					k1=g(p,1);
					k2=h(p,1);
					printf("%d\n",k2-k1-1);
				}
			}
			else 
			{
				ff(q[--i],1);
				flag[q[i]]=0;
			}
		}
	}
	return 0;
}