#include<stdio.h>
int main()
{
	long n,i,j;
	scanf("%d",&j);
	while(j--)
	{
		scanf("%ld",&n);
		for(i=10;i<n;i*=10)
		{
			if(n%i>=5*i/10) n+=i;
			n-=n%i;
		}
		printf("%ld\n",n);
	}
	return 0;
}