#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 100010

struct node
{
	int min,max;
	int col;
	int cov;
}a[maxn*3+10];
void build(int x,int min,int max)
{
	a[x].min=min;
	a[x].max=max;
	a[x].col=0;
	a[x].cov=0;
	int mid=(min+max)/2;
	if(min<max)
	{
//		int mid=(min+max)/2;
		build(x*2,min,mid);
		build(x*2+1,mid+1,max);
	}
}
void insert(int x,int min,int max,int col)
{
	if(min<=a[x].min&&max>=a[x].max) 
	{
		a[x].col=col;
	//	a[x].cov=col;
		return ;
	}
	else
	{
		if(a[x].col!=-1)
		{
			insert(x*2,a[x].min,a[x].max,a[x].col);
			insert(x*2+1,a[x].min,a[x].max,a[x].col);
			a[x].col=-1;
		}
		int mid=(a[x].min+a[x].max)/2;
		if(min<=mid) insert(x*2,min,max,col);
		if(max>mid) insert(x*2+1,min,max,col);
	}
}
int find(int x,int k)
{
	if(a[x].col!=-1) return a[x].col;
	if(a[x].min==a[x].max) return a[x].col;
	int mid=(a[x].min+a[x].max)/2;
	
	if(k<=mid) return find(x*2,k);
	else return find(x*2+1,k);
}
int id[maxn*3];
int seg[maxn][2];
void check(int x)
{
	if(a[x].col!=-1) id[a[x].col]=1;
	else check(x*2),check(x*2+1);
}
int data[maxn*3];
int cnt;
int get(int k)
{
	int min,max;
	int mid;
	min=0;
	max=cnt-1;
	while(min<max)
	{
		mid=(min+max)/2;
		if(data[mid]>=k) max=mid;
		else min=mid+1;
	}
	return min;
}
int main()
{
	int t;
	int i,j;
	scanf("%d",&t);
	int n,m;
	while(t--)
	{
		scanf("%d",&n);
		m=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&seg[i][0],&seg[i][1]);
			id[m++]=seg[i][0];
			id[m++]=seg[i][1];
		}
		sort(id,id+m);

		j=1;
		cnt=0;
		data[cnt++]=id[0];
		for(i=1;i<m;i++)
		{
			if(id[i]!=id[i-1]) data[cnt++]=id[i];
		}
		build(1,0,cnt-1);
		m=cnt-1;
		for(i=0;i<n;i++)
		{
	//		cout<<mp[seg[i][0]]<<" "<<mp[seg[i][1]]<<endl;
			insert(1,get(seg[i][0]),get(seg[i][1]),i+1);
		}
		for(i=1;i<=n;i++) id[i]=0;
	/*	for(i=1;i<=m;i++)
		{
	//		cout<<find(1,i)<<endl;
			id[find(1,i)]=1;
		}
		*/
		check(1);
		int ans=0;
		for(i=1;i<=n;i++) ans+=id[i];
		printf("%d\n",ans);
	}
	return 0;
}
