#include<stdio.h>
#define lenth 16200
int main()
{
	int n,speed,time,i,sum;
	while(scanf("%d",&n)&&n)
	
	{
		sum=1000000;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&speed,&time);
			if(time<0)continue;
			else
			{
				time+=lenth%speed?lenth/speed+1:lenth/speed;
				sum=sum>time?time:sum;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}