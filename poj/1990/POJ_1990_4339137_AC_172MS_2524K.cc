#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 20100
struct node
{
	int x,y;
}a[maxn];
typedef long long lld;
lld ans;
struct  tree
{
	lld sum1,sum2;
	int min,max,cnt;
}t[maxn*4];
int maxsize=0;
void build(int min,int max,int k)
{
	if(k>maxsize) maxsize=k;
	t[k].min=min;
	t[k].max=max;
	t[k].cnt=0;
	t[k].sum1=t[k].sum2=0;
	if(min<max)
	{
		int mid=(min+max)/2;
		build(min,mid,k*2);
		build(mid+1,max,k*2+1);
	}
}
void insert(int i,lld sum1,lld sum2,int k)
{
	t[k].sum1+=sum1;
	t[k].sum2+=sum2;
	t[k].cnt++;
	if(t[k].min<t[k].max)
	{
		int mid=(t[k].min+t[k].max)/2;
		if(i<=mid) insert(i,sum1,sum2,k*2);
		else insert(i,sum1,sum2,k*2+1);
	}
}

lld find(int min,int max,int k,int flag,int &cnt)
{
	cnt=0;
	if(min<=t[k].min&&max>=t[k].max) 
	{
		cnt=t[k].cnt;
		if(flag) return t[k].sum1;
		else return t[k].sum2;
	}
	else
	{
		int mid=(t[k].min+t[k].max)/2;
		lld ans=0;
		int cnt1=0,cnt2=0;
		if(min<=mid) ans+=find(min,max,k*2,flag,cnt1);
		if(max>mid) ans+=find(min,max,k*2+1,flag,cnt2);
		cnt=cnt1+cnt2;
		return ans;
	}
}

bool cmp(const node &x,const node &y)
{
	return x.x<y.x;
}
int main()
{
	lld ans;
	int n,i,j,cnt;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		build(0,maxn,1);
		ans=0;
		lld ans1,ans2;
		for(i=0;i<n;i++)
		{
			ans1=find(0,a[i].y,1,0,cnt);
			if(cnt)
			{
				ans1=ans1-(lld)((lld)(maxn-a[i].y)*(lld)cnt);
				ans1*=a[i].x;
				ans+=ans1;
			}
			ans1=find(a[i].y,maxn,1,1,cnt);
			if(cnt)
			{
				ans1=ans1-(lld)((lld)a[i].y*(lld)cnt);
				ans1*=a[i].x;
				ans+=ans1;
			}
			ans1=a[i].y;
			ans2=maxn-ans1;
			insert(a[i].y,ans1,ans2,1);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}