#include<stdio.h>
#include<queue>
using namespace std;
#define maxn  2000
int dp[maxn][maxn][2];
int a[maxn][maxn];
bool flag[maxn][maxn];
int n,m;
void init()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(flag[i][j]) dp[i][j][0]=i,dp[i][j][1]=j;
			else dp[i][j][0]=dp[i][j][1]=-maxn;
			if(i&&dp[i][j][0]+dp[i][j][1]<dp[i-1][j][0]+dp[i-1][j][1])
			{
				dp[i][j][0]=dp[i-1][j][0];
				dp[i][j][1]=dp[i-1][j][1];
			}
			if(j&&dp[i][j][0]+dp[i][j][1]<dp[i][j-1][0]+dp[i][j-1][1])
			{
				dp[i][j][0]=dp[i][j-1][0];
				dp[i][j][1]=dp[i][j-1][1];
			}
			if(a[i][j]>(i+j-dp[i][j][0]-dp[i][j][1])) a[i][j]=i+j-dp[i][j][0]-dp[i][j][1];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=m-1;j>=0;j--)
		{
			if(flag[i][j]) dp[i][j][0]=i,dp[i][j][1]=j;
			else dp[i][j][0]=-2*maxn,dp[i][j][1]=2*maxn;
			if(i&&dp[i][j][1]-dp[i][j][0]>dp[i-1][j][1]-dp[i-1][j][0]) 
				dp[i][j][0]=dp[i-1][j][0],dp[i][j][1]=dp[i-1][j][1];
			if(j+1<m&&dp[i][j][1]-dp[i][j][0]>dp[i][j+1][1]-dp[i][j+1][0])
				dp[i][j][0]=dp[i][j+1][0],dp[i][j][1]=dp[i][j+1][1];
			if(a[i][j]>(i-j+dp[i][j][1]-dp[i][j][0])) a[i][j]=i-j+dp[i][j][1]-dp[i][j][0];
		}
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<m;j++)
		{
			if(flag[i][j]) dp[i][j][0]=i,dp[i][j][1]=j;
			else dp[i][j][0]=2*maxn,dp[i][j][1]=-2*maxn;
			if(i+1<n&&dp[i][j][0]-dp[i][j][1]>dp[i+1][j][0]-dp[i+1][j][1]) 
				dp[i][j][0]=dp[i+1][j][0],dp[i][j][1]=dp[i+1][j][1];
			if(j&&dp[i][j][0]-dp[i][j][1]>dp[i][j-1][0]-dp[i][j-1][1])
				dp[i][j][0]=dp[i][j-1][0],dp[i][j][1]=dp[i][j-1][1];
			if(a[i][j]>(j-i+dp[i][j][0]-dp[i][j][1])) a[i][j]=j-i+dp[i][j][0]-dp[i][j][1];
		}
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=m-1;j>=0;j--)
		{
			if(flag[i][j]) dp[i][j][0]=i,dp[i][j][1]=j;
			else dp[i][j][0]=2*maxn,dp[i][j][1]=2*maxn;
			if(i+1<n&&dp[i][j][0]+dp[i][j][1]>dp[i+1][j][0]+dp[i+1][j][1]) 
				dp[i][j][0]=dp[i+1][j][0],dp[i][j][1]=dp[i+1][j][1];
			if(j+1<m&&dp[i][j][0]+dp[i][j][1]>dp[i][j+1][0]+dp[i][j+1][1])
				dp[i][j][0]=dp[i][j+1][0],dp[i][j][1]=dp[i][j+1][1];
			if(a[i][j]>(dp[i][j][0]+dp[i][j][1]-i-j)) a[i][j]=dp[i][j][0]+dp[i][j][1]-i-j;
		}
	}
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct node
{
	int x,y,cnt;
}q[1000000];
int x,y,xx,yy;
int f(int mid,int &ans)
{
	int st,en,i,kx,ky,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++) flag[i][j]=0;
	}
	q[0].x=x;
	q[0].y=y;
	q[0].cnt=0;
	flag[x][y]=1;
	st=0;
	en=1;
	while(st<en)
	{
		if(q[st].x==xx&&q[st].y==yy)
		{
			ans=q[st].cnt;
			return 1;
		}
		for(i=0;i<4;i++)
		{
			kx=q[st].x+dx[i];
			ky=q[st].y+dy[i];
			if(kx>=0&&kx<n&&ky>=0&&ky<m&&flag[kx][ky]==0&&a[kx][ky]>=mid)
			{
				flag[kx][ky]=1;
				q[en].x=kx;
				q[en].y=ky;
				q[en].cnt=q[st].cnt+1;
				en++;
			}
		}
		st++;
	}
	return 0;
}
int main()
{
	int i,j,k;
	int min,max,mid,ans1,ans2;
	int t;
	//freopen("testdata.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&k,&n,&m);
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) 
				flag[i][j]=0,a[i][j]=maxn*2+100;
		}
		while(k--)
		{
			scanf("%d%d",&i,&j);
			flag[i][j]=1;
		}
		init();
/*		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) printf("%d ",a[i][j]);
			printf("\n");
		} */
		min=0;
		max=a[x][y];
		ans1=-1;
		while(min<max)
		{
			mid=(min+max)/2;
			if(f(mid,i))
			{
				if(ans1<mid) ans1=mid,ans2=i;
				min=mid+1;
			}
			else max=mid;
		}
		if(f(min,i))
		{
			if(ans1<min) ans1=min,ans2=i;
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}