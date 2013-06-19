#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100100
struct node
{
	int x,y;
	int max;
}a[3000100];
int m;
int max(int x,int y)
{
	if(x>y) return x;
	else return y;
}
int big=0;
void build(int minx,int maxx,int n)
{
	big=max(big,n);
	a[n].x=minx;
	a[n].y=maxx;
	a[n].max=-1;
	int mid=(minx+maxx)/2;
	if(maxx>minx)
	{
		build(minx,mid,n*2);
		build(mid+1,maxx,n*2+1);
	}
}
void insert(int y,int k,int n)
{
	a[n].max=max(a[n].max,k);
	if(a[n].x==a[n].y) return ;
	int mid=(a[n].x+a[n].y)/2;
	if(y<=mid) insert(y,k,n*2);
	else insert(y,k,n*2+1);
}
int find(int minx,int maxx,int n)
{
	if(minx<=a[n].x&&maxx>=a[n].y) return a[n].max;
	int mid=(a[n].x+a[n].y)/2;
	int ans=-1;
	if(minx<=mid) ans=max(ans,find(minx,maxx,n*2));
	if(maxx>mid) ans=max(ans,find(minx,maxx,n*2+1));
	return ans;
}
struct data
{
	int x,y;
}b[maxn];
bool cmp(const data& x,const data& y)
{
	if(x.x==y.x) return x.y>y.y;
	else return x.x>y.x;
}
bool cmp1(const data& x,const data& y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
vector<data> ans[maxn];
int main()
{
	int n,i,j,k,l;
	int tp;
	while(scanf("%d",&n)!=EOF)
	{
		tp=-1;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&b[i].x,&b[i].y);
			tp=max(tp,b[i].y);
			ans[i].clear();
		}
		sort(b,b+n,cmp);
		build(0,tp,1);
		if(big>3000000) while(1);
		for(i=0;i<n;i=l)
		{
			for(l=i+1;l<n&&b[l].x==b[i].x&&b[l].y==b[i].y;l++);
			j=find(b[i].y,tp,1)+1;
			for(k=i;k<l;k++)	ans[j].push_back(b[k]);
			insert(b[i].y,j,1);
		}
		for(i=0;i<n;i++)
		{
			if(ans[i].size()==0) break;
			printf("%d:",ans[i].size());
			sort(ans[i].begin(),ans[i].end(),cmp1);
			for(j=0;j<ans[i].size();j++) printf(" (%d,%d)",ans[i][j].x,ans[i][j].y);
			printf("\n");
		}
	}
	return 0;
}