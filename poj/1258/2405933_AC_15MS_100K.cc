#include<stdio.h>
int a[110][110],n;
#define inf 99999999
int prim()
{
	int close[110];
	int i,j,sum=0,t,min;
	for(i=0;i<n;i++)
		close[i]=a[i][0];
	close[0]=inf;
	t=n;
	while(--t)
	{
		min=0;
		for(i=0;i<n;i++)
		{
			min=close[min]>close[i]?i:min;
		}
		sum+=close[min];
		close[min]=inf;
		for(i=0;i<n;i++)
		{
			if(close[i]!=inf&&close[i]>a[i][min]) close[i]=a[i][min];
		}
	}
	return sum;
}
int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) scanf("%d",&a[i][j]);
		}
		printf("%d\n",prim());
	}
	return 0;
}