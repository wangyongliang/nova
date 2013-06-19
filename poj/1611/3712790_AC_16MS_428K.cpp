#include<stdio.h>
#define maxn 100100
int flag[maxn];
int cnt[maxn];
int find(int x)
{
	int y=x;
	while(x!=flag[x])x=flag[x];
	while(y!=x) 
	{
		int z=flag[y];
		flag[y]=x;
		y=z;
	}
	return x;
}
int main()
{
	int n,m;
	int i,x,y,t;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<n;i++) 
		{
			flag[i]=i;
			cnt[i]=1;
		}
		while(m--)
		{
			scanf("%d",&t);
			scanf("%d",&x);
			x=find(x);
			for(i=1;i<t;i++)
			{
				scanf("%d",&y);
				y=find(y);
				if(x!=y)
				{
					flag[y]=x;
					cnt[x]+=cnt[y];
				}
			}
		}
		x=find(0);
		printf("%d\n",cnt[x]);
	}
	return 0;
}