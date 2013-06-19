#include<stdio.h>
int  main()
{
	int i,n,temp,j;
	long sum1,sum2;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&j);
		sum1=j;
		for(i=1;i<n&&j>sum1;i++)
		{
			scanf("%d",&j);
			sum1=j;
		}
		if(i<n) sum2=sum1-j;
		else sum2=0;
		for(;i<n;i++)
		{
			scanf("%d",&j);
			temp=sum2;
			sum2=sum1-j>sum2?sum1-j:sum2;
			sum1=temp+j>sum1?temp+j:sum1;
		}
		printf("%ld\n",sum1>sum2?sum1:sum2);
	}
	return 0;
}