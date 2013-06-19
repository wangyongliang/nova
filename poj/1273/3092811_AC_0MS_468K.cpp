/*#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 300
int a[maxn][maxn];
int flag[maxn][3];
int flow[maxn][maxn];
int n,m;
int ans;
#define inf 0x7fffffff
void flow_max()
{
	int i,j,st,en,k;
	int q[maxn*2];
	ans=0;
	while(1)
	{
		for(i=1;i<=n;i++) flag[i][0]=0;
		q[0]=1;
		flag[1][0]=1;
		flag[1][1]=inf;
		flag[1][2]=0;
		st=0;
		en=1;
		while(st<en)
		{
			i=q[st];
			for(j=2;j<=n;j++)
			{
				if(flag[j][0]==0&&flow[i][j]<a[i][j])
				{
					flag[j][0]=1;
					flag[j][1]=flag[i][1]>a[i][j]-flow[i][j]?a[i][j]-flow[i][j]:flag[i][1];
					flag[j][2]=i;
					q[en++]=j;
				}
				if(flag[j][0]==0&&flow[j][i])
				{
					flag[j][0]=1;
					flag[j][1]=flag[i][1]>flow[j][i]?flow[j][i]:flag[i][1];
					flag[j][1]=-1*i;
					q[en++]=j;
				}
			}
			st++;
			if(flag[n][0]) break;
		}
		if(flag[n][0])
		{
			i=flag[n][2];
			j=n;
			ans+=flag[n][1];
			while(i!=0)
			{
			//	ans[j]+=flag[n][1];
				k=1;
				if(i<0) k=-1,i*=-1;
				flow[i][j]+=flag[n][1]*k;
				j=i;
				i=flag[i][2];
			}
		}
		else return ;
	}
}
int main()
{
	int i,j,k;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) a[i][j]=flow[i][j]=0;
		}
		while(m--)
		{
			scanf("%d%d%d",&i,&j,&k);
			a[i][j]+=k;
		}
		flow_max();
		printf("%d\n",ans);
	}
}*/
#include<stdio.h>             //POJ1273
#include<memory.h>
#include<math.h>
#include<stdlib.h>

const int SIZE = 201;
const int max = 10000000;
struct Point{
	int c,f;
}net[SIZE][SIZE];               //网络，c为容量，f为流量。
int pre[SIZE],s,t,n,m;
int queue[SIZE],head,tail;

bool bfs()
{
	int i;
	head = tail = 0;
	memset(pre,0,sizeof(pre));
	queue[tail++] = s;
	pre[s] = s;
	while(tail != head){
		int temp = queue[head++];
		for(i = 1; i <= m; i++)
			if(pre[i] == 0 &&
				(net[temp][i].c>net[temp][i].f 
				|| net[i][temp].c>0 && net[i][temp].f>0))
			{
				if(net[temp][i].f < net[temp][i].c)
					pre[i] = temp;         //若为前向弧
				else if(net[i][temp].f > 0)         //若为后向弧
					pre[i] = -temp;
				if(i == t){
					return true;
				}
				else
					queue[tail++] = i;
			}
	}
	return false;
}
int maxflow()
{
	int flow = 0,i;
	while(bfs()){
		int dx = 0x7FFFFFFF;
		int temp;
		for(i = t; i != s; i = abs(pre[i])){
			if(pre[i] >= 0)
				temp = net[pre[i]][i].c-net[pre[i]][i].f;
			else
				temp = net[i][-pre[i]].f;
			if(dx > temp)
				dx = temp;                 //寻找最小增量
		}
		for(i = t; i != s; i= abs(pre[i])){
			if(pre[i] >= 0)
				net[pre[i]][i].f += dx;                //前向弧
            else
				net[i][-pre[i]].f -= dx;              //前向弧
		}
		flow += dx;
	}
	return flow;
}

int main()
{
	int i,j,x,y,z;
	while(scanf("%d %d",&n,&m) == 2){
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++){
				net[i][j].c = 0;
				net[i][j].f = 0;
			}
			for(i = 1; i <= n; i++){
				scanf("%d %d %d",&x,&y,&z);
				net[x][y].c += z;      //注意建图时有无重复边。
			}
			s = 1; t = m;
			int out = maxflow();
			printf("%d\n",out);
	}
	return 0;
}
