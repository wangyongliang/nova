#include<stdio.h>
int main()
{
	int i,n,sum;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d",&n)&&n)
	{
		if(n==1) 
		{
			printf("    1  DEFICIENT\n");
			continue;
		}
		sum=1;
		for(i=2;i*i<n;i++)
		{
			if(n%i==0) sum+=i+n/i;
		}
		if(i*i==n) sum+=i;
		if(sum==n)
			printf("%5d  PERFECT\n",n);
		else if(sum<n)
			printf("%5d  DEFICIENT\n",n);
		else 
			printf("%5d  ABUNDANT\n",n);
	}
	printf("END OF OUTPUT\n");
	return 0;
}