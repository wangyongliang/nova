#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int a[5];
};
int dp[23][23][1<<10];
struct cmp
{
	bool operator ()(const node &x,const node &y)
	{
		int i;
		for(i=0;i<5;i++)
		{
			if(x.a[i]<y.a[i]) return 1;
			else if(x.a[i]>y.a[i]) return 0;
		}
		return 1;
	}
};
priority_queue<node,vector<node>,cmp> heap;
int n,m,cnt;
void init()
{
	while(heap.size()) heap.pop();
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(k=0;k<(1<<cnt);k++) 
			{
				dp[i][j][k]=-1;
			}
		}
	}
}
char s[33][33];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int flg[300];
int main()
{
	int t,i,j,k,xx,yy,p;
	scanf("%d",&t);
	node tp,tp1;
	int a[15],b[15];
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&cnt,&p);
		init();
		for(i=0;i<300;i++) flg[i]=0;
		for(i=0;i<n;i++) 
		{
			scanf("%s",s[i]);
			for(j=0;j<m;j++)
			{
				flg[s[i][j]]=1;
				if(s[i][j]=='*')
				{
					xx=i;
					yy=j;
					dp[i][j][0]=p;
					tp.a[0]=p;
					tp.a[1]=0;
					tp.a[2]=i;
					tp.a[3]=j;
					tp.a[4]=1;
					heap.push(tp);
				}
			}
		}
		j=0;
		for(i='A';i<='Z';i++)
		{
			if(flg[i]) flg[i]=j++;
		}
		for(i=0;i<cnt;i++) scanf("%d%d",&a[i],&b[i]);
		int x,y,tx,ty,z;
		while(heap.size())
		{
			tp=heap.top();
			heap.pop();
			x=tp.a[2];
			y=tp.a[3];
			z=tp.a[1];
			if(tp.a[0]<dp[x][y][z]) continue;
			if(x==xx&&y==yy&&z==((1<<cnt)-1)) break;
			if(tp.a[0]<0) break;
			for(i=0;i<4;i++)
			{
				tx=x+dx[i];
				ty=y+dy[i];
				if((tx>=0&&tx<n)&&(ty>=0&&ty<m)&&s[tx][ty]!='#')
				{
					if(tx==xx&&ty==yy)
					{
						if(z!=(1<<cnt)-1) continue;
						if(dp[tx][ty][z]<tp.a[0]-tp.a[4])
						{
							dp[tx][ty][z]=tp.a[0]-tp.a[4];
							tp1=tp;
							tp1.a[0]=tp.a[0]-tp.a[4];
							tp1.a[2]=tx;
							tp1.a[3]=ty;
							heap.push(tp1);
						}
					}
					else
					{
						if(dp[tx][ty][z]<tp.a[0]-tp.a[4])
						{
							dp[tx][ty][z]=tp.a[0]-tp.a[4];
							tp1=tp;
							tp1.a[0]=tp.a[0]-tp.a[4];
							tp1.a[2]=tx;
							tp1.a[3]=ty;
							heap.push(tp1);
						}
						if(s[tx][ty]>='A'&&s[tx][ty]<='z')
						{
							k=flg[s[tx][ty]];
							k=1<<k;
							if((z|k)==z+k)
							{
								z|=k;
								if(dp[tx][ty][z]<tp.a[0]-tp.a[4]-a[flg[s[tx][ty]]])
								{
									tp1.a[0]=tp.a[0]-tp.a[4]-a[flg[s[tx][ty]]];
									tp1.a[1]=z;
									tp1.a[2]=tx;
									tp1.a[3]=ty;
									tp1.a[4]=tp.a[4]+b[flg[s[tx][ty]]];
									heap.push(tp1);
								}
							}
							z=tp.a[1];
						}
					}
				}
			}
		}
//		printf("%d\n",max);
		if(dp[xx][yy][(1<<cnt)-1]<0) printf("Impossible\n");
		else printf("%d\n",p-dp[xx][yy][(1<<cnt)-1]);
	}
	return 0;
}