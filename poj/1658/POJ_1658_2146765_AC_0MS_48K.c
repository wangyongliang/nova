#include<stdio.h>
void main()
{
	long i,j,k,l,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%ld %ld %ld %ld",&i,&j,&k,&l);
		if(i+l==j+k)
			printf("%ld %ld %ld %ld %ld\n",i,j,k,l,j+l-i);
		else
			printf("%ld %ld %ld %ld %ld\n",i,j,k,l,j/i*l);
	}
}