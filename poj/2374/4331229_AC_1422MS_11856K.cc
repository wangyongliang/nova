#include<iostream>
using namespace std;
#define maxn 200100
#define inf 1000000
#define size 100000
#define abs(x) (x)>0?(x):-(x)
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
	if(min<max)
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
int b[maxn][2];
int main()
{
	int n,m;
	int i,j,tp1,tp2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		m+=size;
		for(i=0;i<maxn;i++) dp[i]=inf*2;
		for(i=0;i<n;i++) 
			scanf("%d%d",&b[i][0],&b[i][1]);
		n--;
		i=b[n][0]+size;
		j=b[n--][1]+size;
		dp[i]=abs(m-i);
		dp[j]=abs(m-j);
		build(0,maxn,1);
		insert(i,1);
		insert(j,1);
		while(n>=0)
		{
			i=b[n][0]+size;
			j=b[n--][1]+size;
			dp[i]=getminans1(i,i,1,1)-i;
			dp[j]=getminans1(j,j,1,1)-j;
			tp1=getminans1(i,j,1,1)-i;
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
		}
		tp1=getminans1(0,size,1,0)-(maxn-size);
		tp2=getminans1(size,maxn,1,1)-size;
		if(tp1<tp2) printf("%d\n",tp1);
		else printf("%d\n",tp2);
	}
	return 0;
}