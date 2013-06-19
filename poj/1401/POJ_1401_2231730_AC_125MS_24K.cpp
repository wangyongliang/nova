#include<stdio.h>
void main()
{
	long n,t,sum;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		sum=0;
		while(n)
		{
			n/=5;
			sum+=n;
		}
		printf("%ld\n",sum);
	}
}