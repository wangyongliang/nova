#include<stdio.h>
void main()
{
	long n,k,j;
	int sum;
	while(scanf("%ld %ld",&n,&k)!=EOF)
	{
		sum=0;
		j=n-k;
		while(n||j||k)
		{
			sum=sum+n/2-j/2-k/2;
			n/=2;
			k/=2;
			j/=2;
		}
		if(sum>0)
			printf("0\n");
		else 
			printf("1\n");
	}
}