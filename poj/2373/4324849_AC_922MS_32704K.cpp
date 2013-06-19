#include<iostream>
#include<algorithm>

using namespace std;
#define maxn 1000010
#define MAX(X,Y)((X)>(Y)?(X):(Y))
struct node
{
	int min,max;
	int minans;
}a[3*maxn];
int dp[maxn];
struct pnode
{
	int x,y;
}b[10000];
bool cmp(pnode &x,pnode &y)
{
	if(x.x==y.x) return y.y<y.y;
	return x.x<y.x;
}
int flag[maxn];

void build(int min,int max,int k)
{
	a[k].min=min;
	a[k].max=max;
	if(min==max) 
	{
		a[k].minans=dp[min];
	}
	else
	{
		int mid=(min+max)/2;
		build(min,mid,k*2);
		build(mid+1,max,k*2+1);
		a[k].minans=a[k*2].minans;
	}
}
int find(int min,int max,int k)
{

	if(min<=a[k].min&&max>=a[k].max) return a[k].minans;
	else
	{
		int mid=(a[k].min+a[k].max)/2;
		int tp=0x7fffffff-10;
		if(min<=mid) tp=find(min,max,k*2);
		if(max>mid)
		{
			int tpp=find(min,max,k*2+1);
			if(tp>tpp) tp=tpp;
		}
		return tp;
	}
}
void insert(int i,int k)
{
	if(a[k].min==a[k].max)
	{
		if(a[k].minans>dp[i])	a[k].minans=dp[i];
	}
	else
	{
		if(dp[i]<a[k].minans) a[k].minans=dp[i];
		int mid=(a[k].min+a[k].max)/2;
		if(i<=mid) insert(i,k*2);
		else insert(i,k*2+1);
	//	if(a[k*2].minans<)
	}
}
int main()
{
	int l,n;
	int A,B;
	int i,j;
	int min,max;
	while(scanf("%d%d",&n,&l)!=EOF)
	{
		scanf("%d%d",&A,&B);
		for(i=0;i<=l;i++)
		{
			flag[i]=1;
			dp[i]=l*2;
		}
		dp[0]=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d%d",&b[i].x,&b[i].y);
			if(b[i].x>b[i].y) swap(b[i].x,b[i].y);
			b[i].x++;
		}
		sort(b,b+n,cmp);
		int t=0;
		for(i=0;i<n;i++)
		{
			if(b[i].x>t) t=b[i].x;
			for(;t<b[i].y;t++) flag[t]=0;
		}
		build(0,l,1);
		for(i=2;i<=l;i+=2)
		{
			if(flag[i])
			{ 
				if(i==2000)
				{
					printf("");
				}
				max=i-2*A;
				min=i-2*B;
				if(max<0) continue;
				if(min<0) min=0;
				int tp=find(min,max,1)+1;
			//	if(tp==0x7fffffff) continue;
				if(tp<dp[i]) 
				{
					dp[i]=tp;
					insert(i,1);
				}
			}
		}
		if(dp[l]>=l*2) printf("-1\n");
		else printf("%d\n",dp[l]);
		
	}
	return 0;
}