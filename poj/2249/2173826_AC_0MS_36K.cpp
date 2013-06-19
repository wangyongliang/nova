#include<stdio.h>
void main()
{ double sum;
  unsigned long i,n,k;
    scanf("%ld %ld",&n,&k);
    while(n!=0)
	{
		sum=1;
		if(k>n/2) k=n-k;
		for( i=1;i<=k;i++)
		{ sum=sum/i;
		  sum=sum*(n-i+1);
		}
		printf("%.0f\n",sum);
		scanf("%ld %ld",&n,&k);
	}
}
