#include<stdio.h>
void main()
{
	int n,k;
	int sum;
	while(scanf("%ld %ld",&n,&k)!=EOF)
	{
		sum=0;
		while(n||k)
		{
			sum=sum+n/2-(n-k)/2-k/2;
			n=n>>1;
			k=k>>1;
		}
		if(sum>0)
			printf("0\n");
		else 
			printf("1\n");
	}
}
