/*#include<stdio.h>
int fun(unsigned long n)
{
    unsigned long i;
	int sum=0;
	i=n;
	while(i%2==0)
	{
		sum++;
		i/=2;
	}
	return sum;
}
void main()
{
	unsigned long k,n,i,j,sum;
	while(scanf("%u %u",&n,&k)!=EOF)
	{
		if(k==0)
			printf("1\n");
		else
		{
			sum=0;
			if(k>n/2)k=n-k;
			if(n&1)i=n-1;
			else i=n;
			for(;i>=n-k+1;i-=2)sum+=fun(i);
			if(k&1)i=k-1;
			else i=k;
			for(;i>=1;i-=2)sum-=fun(i);
			if(sum>0)
				printf("0\n");
			else
				printf("1\n");
		}
	}
}*/
#include<stdio.h>
long jisuan(long n)
{
	long sum=0;
	while(n!=0)
	{
		sum+=n/2;
		n/=2;
	}
	return sum;
}
void main()
{
	long n,k,sum;
	while(scanf("%ld %ld",&n,&k)!=EOF)
	{
		sum=0;
		sum+=jisuan(n);
		sum-=jisuan(k);
		sum-=jisuan(n-k);
		if(sum>0)
			printf("0\n");
		else 
			printf("1\n");
	}
}