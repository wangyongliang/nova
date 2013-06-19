#include<stdio.h>
long gcd(long n,long m)
{
	long k;
	if(n<m)
	{
		k=n;
		n=m;
		m=k;
	}
	while(m)
	{
		k=n%m;
		n=m;
		m=k;
	}
	return n;
}
void main()
{
	long n,k,i;
	double sum,max,l;
	while(1)
	{
		scanf("%ld%ld",&n,&k);
		if(n==0&&k==0) break;
		if(k>n/2)k=n-k;
		for(sum=max=i=1;i<=k;i++)
		{
			sum*=n--;
			max*=i;
			l=gcd(sum,max);
			sum/=l;
			max/=l;
		}
		sum/=max;
		printf("%.0lf\n",sum);
	}
}