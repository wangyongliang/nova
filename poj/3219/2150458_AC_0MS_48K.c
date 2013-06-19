#include<stdio.h>
void main()
{
	long n,k,j;
	int sum;
	while(scanf("%ld %ld",&n,&k)!=EOF)
	{
		sum=0;
		j=n;
		while(j!=0)
		{
			sum+=j/2;
			j/=2;
		}
		j=k;
		while(j!=0)
		{
			sum-=j/2;
			j/=2;
		}
		j=n-k;
		while(j!=0)
		{
			sum-=j/2;
			j/=2;
		}
		if(sum>0)
			printf("0\n");
		else 
			printf("1\n");
	}
}