#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 200100
int a[maxn],sa[maxn],height[maxn],h[maxn],rank[maxn],n;
int k;
int rrank[maxn];
bool cmplst(const int& x, const int& y){  return rrank[x]<rrank[y]||rrank[x]==rrank[y]&&rrank[x+k]<rrank[y+k];}
bool cmp1(const int &x,const int &y){	return a[x]<a[y];}
bool cmp2(const int &x,const int &y){	return height[x]<height[y];}
void suffix_arry()
{
	int i,j;
	for(i=0;i<n;i++) sa[i]=i;
	sort(sa,sa+n,cmp1);
	for(j=i=0;i<n;i++)
	{
		if(i>0&&a[sa[i-1]]!=a[sa[i]]) j++;
		rank[sa[i]]=j;
	}
	for(k=1;rank[sa[n-1]]<n-1;k*=2)
	{
		for(i=0;i<n;i++) rrank[i]=rank[i];
		sort(sa,sa+n,cmplst);
		for(j=i=0;i<n;i++)
		{
			if(i>0&&cmplst(sa[i-1],sa[i])) j++;
			rank[sa[i]]=j;
		}
	}
//	for(i=0;i<n;i++) printf("%d ",sa[i]);
//	printf("\n");
//	for(i=0;i<n;i++) printf("%d ",rank[i]);
//	printf("\n");
	for(i=0;i<n;i++)
	{
		if(rank[i]==0) 
		{
			h[i]=0;
			continue;
		}
		if(i==0||h[i-1]<=1) k=0;
		else k=h[i-1]-1;
		j=sa[rank[i]-1];
		for(;i+k<n&&j+k<n;k++)
		{
			if(a[i+k]!=a[j+k]) break;
		}
		h[i]=k;
	}
	for(i=0;i<n;i++) height[rank[i]]=h[i];
//	for(i=0;i<n;i++) printf("%d ",height[i]);
//	printf("\n");
}
int f[maxn],rr[maxn],ll[maxn];
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
int set_find(int x)
{
	if (x != f[x]) f[x] = set_find(f[x]);
	return f[x];
}
void set_union(int x, int y)
{
	int rx, ry;
	rx = set_find(x);
	ry = set_find(y);
	f[ry] = rx;
	ll[rx] = min(ll[rx], ll[ry]);
	rr[rx] = max(rr[rx], rr[ry]);
}
int main()
{
	int i,j;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&a[0]);
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i-1]=a[i]-a[i-1];
		}
		a[n]=-100;
		suffix_arry();
		for(i=0;i<n;i++) rrank[i]=i;
		sort(rrank,rrank+n,cmp2);
		for(i=0;i<n;i++) f[i]=ll[i]=rr[i]=i;
		for(i=n-1;i>=0;i--)
		{
			if(height[rrank[i]]<4) break;
			set_union(sa[rrank[i]],sa[rrank[i]-1]);
			int tmp=set_find(sa[rrank[i]]);
			if (rr[tmp] - ll[tmp] > height[rrank[i]]) break;
		}
		if (height[rrank[i]] >= 4)
			printf("%d\n", height[rrank[i]] + 1);
		else printf("0\n");
	}
}