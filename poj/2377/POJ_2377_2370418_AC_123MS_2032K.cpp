#include<stdio.h>/*prime*/
#define inf 9999999
int cost[1010],a[(1010+1)*505];/*a[]是用来放图。i,j的关系放在a[(1+i)*i/2+j],*/
int fun(int x,int y)
{
	int temp;
	if(x<y)
	{
		temp=x;
		x=y;
		y=temp;
	}
	return (x-1)*x/2+y;
}
int main()
{
	int i,j,sum,t,max,vecter,n,m,temp;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=(1+n)*n/2+1;i++)a[i]=inf;/*初始化*/
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&t,&j,&sum);
			temp=fun(t,j);
			if(a[temp]!=inf) /*有重边的时候放最大的那个*/
			{
				if(a[temp]<sum) a[temp]=sum;
			}
			else a[temp]=sum;
		}
		for(i=1;i<=n;i++) /*用顶点1初始cost[]*/
		{
			temp=fun(1,i);
			cost[i]=a[temp];
		}
		cost[1]=-1;
		for(sum=0,t=1;t<n;t++)
		{
			for(max=0,i=1;i<=n;i++) 
			{
				if(cost[i]!=inf&&max<cost[i]) max=cost[i],vecter=i; /*找到最大的cost[]*/
			}
			if(max==0)
			{
				sum=-1;
				goto out;
			}
			sum+=max;
			cost[vecter]=-1;
			for(i=1;i<=n;i++)
			{
				if(cost[i]!=-1)
				{
					temp=fun(i,vecter);
					if(cost[i]!=inf)
					{
						if(cost[i]<a[temp]&&a[temp]!=inf)
							cost[i]=a[temp];
					}
					else cost[i]=a[temp];/*没有边直接相连的直接改变*/
				}
			
			}
		}
out:
		printf("%d\n",sum);

	}
	return 0;
}