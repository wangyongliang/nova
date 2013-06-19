#include<stdio.h>
#define inf 66336
int minn(int x,int y)
{
	return x>y?y:x;
}
int cost[510],a[510][510],n;
int prime()
{
	int i,min,t,sum,vecter;
	for(i=1;i<=n;i++)
		cost[i]=minn(a[i][1],a[1][i]);
	cost[1]=inf;
	for(t=1,sum=0;t<n;t++)
	{
		for(i=1,min=inf;i<=n;i++)
		{
			if(cost[i]<min) 
			{
				min=cost[i];
				vecter=i;
			}
		}
		cost[vecter]=inf;
		sum=min>sum?min:sum;
		for(i=1;i<=n;i++)
		{
			min=minn(a[i][vecter],a[vecter][i]);
			if(cost[i]>min&&cost[i]!=inf) cost[i]=min;
		}
	}
	return sum;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
				if(i==j)a[i][j]=inf;
			}
		}
		printf("%d\n",prime());
	}
	return 0;
}
