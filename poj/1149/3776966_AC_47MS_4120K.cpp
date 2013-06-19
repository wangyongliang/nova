#include <stdio.h>
#include <math.h>
#include <memory.h>
#define Inf 0x7fffffff
#define MAX 0x7fffffff
#define size 1000
int cap[size][size],prev[size],s,t,flow[size][size];
//cap为容量，flow为流量 
int queue[size],head,tail,visited[size];
int pighouse[size];
int ans, n, m;
int Flow;
int pre[size];

int bfs()
{
	int i;
	for(i=0;i<=n;i++) pre[i]=-1;
	int q[1100];
	int st,en;
	st=en=0;
	q[en++]=0;
	while(st<en)
	{
		for(i=0;i<=n;i++)
		{
			if(pre[i]==-1&&cap[q[st]][i]>0)
			{
				pre[i]=q[st];
				if(i==n) return 1;
				q[en++]=i;
			}
		}
		st++;
	}
	return 0;
}

int maxflow()
{
	int i, flow = 0;
	int min;
	while(bfs())
	{
		min=0x7fffffff;
		for(i=n;i!=0;i=pre[i]) min=min>cap[pre[i]][i]?cap[pre[i]][i]:min;
		flow+=min;
		for(i=n;i!=0;i=pre[i])
		{
			cap[pre[i]][i]-=min;
			cap[i][pre[i]]+=min;
		}
	}
	return flow;
}



void init()
{
    int i,k,e;   
    for(i = 1; i <= m; i++) 
    {
        scanf("%d",&pighouse[i]);
        prev[i]=0;
    }
    s = 0;
    t = n + 1;     
	memset(cap, 0, sizeof(cap));
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&e);
            if(prev[e] == 0)
            {
                prev[e] = i;
                cap[0][i] += pighouse[e];
            }
            else
            {
                cap[prev[e]][i] = Inf;
                prev[e] = i;
            }
        }
        scanf("%d",&cap[i][n+1]);
    }
	n+=1;
}

int main()
{
    while(scanf("%d%d",&m,&n) != EOF)
    {
        init();
        printf("%d\n",maxflow());
    }
    return 0;
}

