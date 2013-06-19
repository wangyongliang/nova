#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 20100
int n,sa[maxn],rank[maxn],ranklist[maxn],a[maxn],k,h[maxn];
bool cmp(const int &x,const int &y)
{
	return a[x]<a[y];
}
bool cmplist(const int &x,const int &y)
{
	return (ranklist[x]<ranklist[y]||ranklist[x]==ranklist[y]&&ranklist[x+k]<ranklist[y+k]);
}
int height[maxn];
void suffix_array()
{
	int i,j;
	for(i=0;i<n;i++) sa[i]=i;
	sort(sa,sa+n,cmp);
	for(j=i=0;i<n;i++)
	{
		if(i>0&&a[sa[i]]!=a[sa[i-1]]) j++;
		rank[sa[i]]=j;
	}
	for(k=1;rank[sa[n-1]]<n-1;k*=2)
	{
		for(i=0;i<n;i++) ranklist[i]=rank[i];
		sort(sa,sa+n,cmplist);
		for(j=i=0;i<n;i++)
		{
			if(i>0&&cmplist(sa[i-1],sa[i])) j++;
			rank[sa[i]]=j;
		}
	}

	for(i=0;i<n;i++)
	{
		if(rank[i]==0){ h[i]=0;continue;}
		if(i==0||h[i-1]<=1) k=0;
		else k=h[i-1]-1;
		j=sa[rank[i]-1];
		for(;i+k<n&&j+k<n;k++)
		{
			if(a[i+k]!=a[j+k]) break;
		}
		h[i]=k;
	}
	for(i=0;i<n;i++)  height[rank[i]]=h[i];
}
int f[maxn],num[maxn];
bool cmp1(const int &x,const int &y)
{
	return height[x]<height[y];
}
int find(int x)
{
	int y;
	y=x;
	while(y!=f[y]) y=f[y];
	f[x]=y;
	return y;
}
int main()
{
	int i,ans;
	int m;
	int xx,yy;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d",a+i);
		a[n++]=-1;
		suffix_array();
		for(i=0;i<n;i++) f[i]=i,num[i]=1;
		for(i=0;i<n;i++) ranklist[i]=i;
		sort(ranklist,ranklist+n,cmp1);
		ans=0;
		for(i=n-1;i>=0;i--)
		{
			xx=find(sa[ranklist[i]]);
			yy=find(sa[ranklist[i]-1]);
			if(xx!=yy)
			{
				f[yy]=xx;
				num[xx]+=num[yy];
			}
			if(num[xx]>=m) 
			{
				ans=height[ranklist[i]];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
