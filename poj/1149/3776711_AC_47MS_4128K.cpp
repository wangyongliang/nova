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

bool findload()
{
	int i,j;
	memset(visited,0,sizeof(visited));
	head = tail = 0;
	queue[tail++] = s;
	pre[s] = -1;
	while(head < tail)
	{
		j = queue[head++];
		for(i = 0; i <= n; i++)
		{
			if(!visited[i] && cap[j][i] > 0)
			{
				pre[i] = j;
				visited[i] = 1;
				if(i == t)
				{
					return true;
				}
				queue[tail++] = i;
			}
		}
	}
	return false;
}
int maxflow()
{
	int i, j, flow = 0;
	int min;
	while(findload())
	{
		min = 0x7ffffff;
		for(i = t; i!= s; i = pre[i])
		{
			if(cap[pre[i]][i] < min)
			{
				min = cap[pre[i]][i];
			}
		}
		flow += min;
		for(i = t; i != s; i = pre[i])
		{
			cap[pre[i]][i] -= min;
			cap[i][pre[i]] += min;
		}
	}
	return flow;
}



void init()
{
    int i,k,j,e;
   
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



