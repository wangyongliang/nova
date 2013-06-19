#include<stdio.h>
#include<vector>
#include<queue>
#include<time.h>
#include<algorithm>
typedef __int64 lld;
using namespace std;
#define maxn 1000010
struct node
{
	int x,z;
	int y;
}a1[maxn],a2[maxn];
int q[maxn*2];
int flag[maxn];
int n;
lld dis[maxn];
int b1[maxn],b2[maxn],e1[maxn],e2[maxn];

lld spfa(node a[maxn],int b[maxn],int e[maxn])
{
	int i;
	for(i=0;i<n;i++)
	{
		dis[i]=0xfffffffffffffffLL;
		flag[i]=0;
	}
	dis[0]=0;	
	int st,en;
	st=0;
	en=1;
	q[0]=0;
	flag[0]=1;
	while(st!=en)
	{
		flag[q[st]]=0;
		int x=q[st];
		st=(st+1)%maxn;
		for(i=b[x];i<=e[x];i++)
		{
			int xx=a[i].z;
			lld yy=a[i].y;
			if(dis[xx]>dis[x]+yy)
			{
				dis[xx]=dis[x]+yy;
				if(flag[xx]==0)
				{
					flag[xx]=1;
					q[en]=xx;
					en=(en+1)%maxn;
				}
			}
		}
	}
	lld ans=0;
	for(i=0;i<n;i++) ans+=dis[i];
	return ans;
}
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) return x.z<y.z;
	else return x.x<y.x;
}
int main()
{
	int t;
//	freopen("invite.in","r",stdin);
//	freopen("invite.out","w",stdout);
	int st=clock();
	scanf("%d",&t);
	int i,x,y;
	node tp;
	while(t--)
	{
		int m;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			b1[i]=b2[i]=m;
			e1[i]=e2[i]=0;
		}
		for(i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d %d",&a1[i].x,&a1[i].z,&a1[i].y);
			a1[i].x--;
			a1[i].z--;
			a2[i]=a1[i];
			swap(a2[i].x,a2[i].z);
		}
		sort(a1,a1+m,cmp);
		sort(a2,a2+m,cmp);
		for(i=0;i<m;i++)
		{
			if(b1[a1[i].x]==m) b1[a1[i].x]=i;
			e1[a1[i].x]=i;
			if(b2[a2[i].x]==m) b2[a2[i].x]=i;
			e2[a2[i].x]=i;
		}
		lld ans;
		ans=spfa(a1,b1,e1);
		ans+=spfa(a2,b2,e2);
		printf("%I64d\n",ans);
	}
//	int en=clock();
//	printf("tims is %d\n",en-st);
	return 0;
}
