#include<stdio.h>
void main()
{
	long i,j,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%ld %ld",&i,&j);
		if(((i+j)&1)||i<j)
			printf("impossible\n");
		else
		{
			j=(i+j)/2;
			i=i-j;
			printf("%ld %ld\n",j,i);
		}
	}
}