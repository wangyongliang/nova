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

int n;
lld dis[maxn];
int b1[maxn],b2[maxn],e1[maxn],e2[maxn];


int heap[maxn];
int index[maxn];
int cnt;



void shiftdown(int k)
{
	heap[0]=heap[k];
	int i=k;
	int j=k*2;
	while(j<=cnt)
	{
		if(j+1<=cnt&&dis[heap[j+1]]<dis[heap[j]]) j++;
		if(dis[heap[j]]<dis[heap[0]])
		{
			heap[i]=heap[j];
			index[heap[i]]=i;
			i=j;
			j*=2;
		}
		else break;
	}
	heap[i]=heap[0];
	index[heap[i]]=i;

}
void shiftup(int k)
{
	heap[0]=heap[k];
	int i=k;
	int j=k/2;
	while(j>0)
	{
		if(dis[heap[0]]<dis[heap[j]])
		{
			heap[i]=heap[j];
			index[heap[i]]=i;
			i=j;
			j/=2;
		}
		else break;
	}
	heap[i]=heap[0];
	index[heap[i]]=i;
}
long long  dij(node a[maxn],int b[maxn],int e[maxn])
{
	int i;
	for(i=0;i<n;i++)
	{
		dis[i]=0xfffffffffffffffLL;
		index[i]=-1;
	}
	dis[0]=0;
	node tp;
	heap[1]=0;
	index[0]=1;
	cnt=1;
	long long ans=0;
	while(cnt>0)
	{
		int x=heap[1];
		long long y=dis[x];
		heap[1]=heap[cnt--];
		shiftdown(1);
		if(y>dis[x]) continue;
	//	ans+=y;
		for(i=b[x];i<=e[x];i++)
		{
			int xx=a[i].z;
			long long yy=a[i].y+y;
			if(dis[xx]>yy)
			{
				dis[xx]=yy;
				if(index[xx]==-1) 
				{
					index[xx]=++cnt;
					heap[cnt]=xx;
				}
				shiftup(index[xx]);
			}
		}
	}
	ans=0;
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
		ans=dij(a1,b1,e1);
		ans+=dij(a2,b2,e2);
		printf("%I64d\n",ans);
	}
//	int en=clock();
//	printf("tims is %d\n",en-st);
	return 0;
}


