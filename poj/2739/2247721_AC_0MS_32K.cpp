#include<stdio.h>
int a[1229];
void init()
{
	int i,j,k;
	for(a[0]=2,k=1,i=3;i<10000;i++)
	{
		for(j=0;a[j]*a[j]<=i;j++)
		{
			if(i%a[j]==0) break;
		}
		if(a[j]*a[j]>i) a[k++]=i;
	}
}
int main()
{
	int n,i,j,sum,sumi;
	init();
	while(scanf("%d",&n)&&n)
	{
		sumi=0;
		for(i=0;i<1229&&i<=n;i++)
		{
			for(sum=0,j=i;j<1229&&sum<=n;j++)
			{
				sum+=a[j];
				if(sum==n) sumi++;
			}
		}
		printf("%d\n",sumi);
	}
	return 0;
}