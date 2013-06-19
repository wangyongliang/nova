#include<iostream>
using namespace std;
#define maxn 200100
#define inf 1000000
struct node
{
	int min,max;
	int ans1,ans2;
	int col;
}a[maxn*3];
int dp[maxn];
void build(int min,int max,int k)
{
	a[k].min=min;
	a[k].max=max;
	a[k].ans1=a[k].ans2=inf*2;
	a[k].col=0;
	if(min==max) return ;
	else
	{
		int mid=(min+max)/2;
		build(min,mid,k*2);
		build(mid+1,max,k*2+1);
	}
	
}
void cov(int min,int max,int k)
{
	if(min<=a[k].min&&max>=a[k].max)
	{
		a[k].col=1;
		a[k].ans1=a[k].ans2=inf*2;
	}
	else
	{
		if(a[k].col) return;
		int mid=(a[k].min+a[k].max)/2;
		if(min<=mid) cov(min,max,k*2);
		if(max>mid) cov(min,max,k*2+1);
		if(a[k*2].ans1<a[k*2+1].ans1) a[k].ans1=a[k*2].ans1;
		else a[k].ans1=a[k*2+1].ans1;
		if(a[k*2].ans2<a[k*2+1].ans2) a[k].ans2=a[k*2].ans2;
		else a[k].ans2=a[k*2+1].ans2;
	}
}
int getminans1(int min,int max,int k,int flag)
{
	if(min<=a[k].min&&max>=a[k].max)
	{
		if(flag)	return  a[k].ans1;
		else return a[k].ans2;
	}
	else
	{
		if(a[k].col)
		{
			a[k].col=0;
			cov(a[k].min,a[k].max,k*2);
			cov(a[k].min,a[k].max,k*2+1);
		}
		int mid=(a[k].min+a[k].max)/2;
		int tp1,tp2;
		tp1=tp2=inf*2;
		if(min<=mid) tp1=getminans1(min,max,k*2,flag);
		if(max>mid) tp2=getminans1(min,max,k*2+1,flag);
		if(tp1<tp2) return tp1;
		else return tp2;
	}
}
void insert(int i,int k)
{
	int tp1=dp[i]+i;
	int tp2=dp[i]+maxn-i;
	if(tp1<a[k].ans1) a[k].ans1=tp1;
	if(tp2<a[k].ans2) a[k].ans2=tp2;
	if(a[k].min==a[k].max) return ;
	if(a[k].col) 
	{
		a[k].col=0;
		cov(a[k].min,a[k].max,k*2);
		cov(a[k].min,a[k].max,k*2+1);
	}
	int mid=(a[k].min+a[k].max)/2;
	if(i<=mid) insert(i,k*2);
	else  insert(i,k*2+1);
}
int get(int i,int k)
{
	if(a[k].min==a[k].max) return a[k].ans1-i;
	else
	{
		if(a[k].col)
		{
			a[k].col=0;
			cov(a[k].min,a[k].max,k*2);
			cov(a[k].min,a[k].max,k*2+1);
		}
		int mid=(a[k].min+a[k].max)/2;
		if(i<=mid) return get(i,k*2);
		else return get(i,k*2+1);
	}
}
int abs(int x)
{
	if(x>0) return x;
	else return -x;
}
int b[maxn][2];
int main()
{
	int n,m;
	int i,j,tp1,tp2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		m+=100000;
		for(i=0;i<maxn;i++) dp[i]=inf*2;
		for(i=0;i<n;i++) 
		{
			scanf("%d%d",&b[i][0],&b[i][1]);
		}
		n--;
		i=b[n][0];
		j=b[n][1];
		n--;
		i+=100000;
		j+=100000;
		dp[i]=abs(m-i);
		dp[j]=abs(m-j);
		build(0,maxn,1);
		insert(i,1);
		insert(j,1);
		while(n>=0)
		{
		//	scanf("%d%d",&i,&j);
			i=b[n][0];
			j=b[n][1];
			n--;
			i+=100000;
			j+=100000;
			dp[i]=get(i,1);
			dp[j]=get(j,1);
			tp1=getminans1(i,j,1,1)-i;
		//	tp1=-i;
			int flag1,flag2;
			flag1=flag2=0;
			if(tp1<dp[i]&&tp1<inf) {
				flag1=1;
				dp[i]=tp1;
			}
			tp1=getminans1(i,j,1,0)-(maxn-j);
			cov(i+1,j-1,1);
			if(tp1<dp[j]&&tp1<inf)
			{
				flag2=1;
				dp[j]=tp1;
			}
			if(flag1) insert(i,1);
			if(flag2) insert(j,1);
		/*	for(i=99997;i<100003;i++) 
			{
				dp[i]=get(i,1);
				if(dp[i]>inf) dp[i]=2*inf;
			} */

		}
		tp1=getminans1(0,100000,1,0)-(maxn-100000);
		tp2=getminans1(100000,maxn,1,1)-100000;
		if(tp1<tp2) printf("%d\n",tp1);
		else printf("%d\n",tp2);
	}
	return 0;
}