#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 2100000
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
}
int flag[10000],q[maxn],index[maxn];
int m[maxn][20];
void init()
{
	int i,j;
	for(i=0;i<n;i++) m[i][0]=i;
	for(i=1;(1<<i)<=n;i++)
	{
		for(j=0;j+(1<<i)-1<n;j++)
		{
			if(height[m[j][i-1]]<=height[m[j+(1<<(i-1))][i-1]]) 
				m[j][i]=m[j][i-1];
			else m[j][i]=m[j+(1<<(i-1))][i-1];
		}
	}
}
int find(int x,int y)
{
	int i;
	for(i=0;(1<<(i+1))<=y-x+1;i++);
	if(height[m[x][i]]<=height[m[y-(1<<i)+1][i]]) return m[x][i];
	else return m[y-(1<<i)+1][i];
}
char s[maxn];
vector<int> ans;
int main()
{
	int i,j,k;
	int m;
	int x1,y1,k1;
	int longest;
	m=2;
	
	
	n=0;
	for(i=0;i<m;i++) 
	{
		scanf("%s",s);
		for(j=0;s[j];j++)
		{
			a[n]=s[j];
			index[n++]=i;
		}
		a[n]=-n-i;
		index[n++]=i;
	}
	suffix_arry();
	init();
	for(i=0;i<m;i++) flag[i]=0;
	int cnt=0;
	i=j=0;
	longest =0;
	ans.clear();
	y1=-1;
	x1=-1;
	while(j<n)
	{
		q[j]=sa[j];
		if(flag[index[sa[j]]]==0) cnt++;
		flag[index[sa[j]]]++;
		if(cnt==m)
		{
			while(cnt==m)
			{
				flag[index[q[i]]]--;
				if(flag[index[q[i]]]==0) cnt--;
				i++;
			}
			k=find(rank[q[i-1]]+1,rank[q[j]]);
			if(height[k]>=longest) longest=height[k];
		}
		j++;
	}
	printf("%d\n",longest);
	
	return 0;
}


