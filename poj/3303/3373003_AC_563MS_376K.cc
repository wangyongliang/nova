#include<iostream>
#include<algorithm>
using namespace std;
int end[9]={0};
int N;
struct Node
{
	int s,t;
	int h[8],k;
}task[1024];
bool dfs(int t)
{
	if(t>N) return true;
	int i;
	for(i=0;i<task[t].k;i++)
	{
		if(task[t].s>end[task[t].h[i]])
		{
			int tmp=end[task[t].h[i]];
			end[task[t].h[i]]=task[t].t;
			if(dfs(t+1))
			{
				return true;
			}
			end[task[t].h[i]]=tmp;
		}
	}
	return false;
}

int cmp(Node a,Node b)
{
	return a.s<b.s;
}
int main()
{
	int T;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		memset(end,0,sizeof(end));
		scanf("%d",&N);
		for(i=1;i<=N;i++)
		{
			scanf("%d%d%d",&task[i].s,&task[i].t,&task[i].k);
			for(j=0;j<task[i].k;j++)
			{
				scanf("%d",&task[i].h[j]);
			}
		}
		sort(task+1,task+1+N,cmp);
		if(dfs(1))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 1;
}