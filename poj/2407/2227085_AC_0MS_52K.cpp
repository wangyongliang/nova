#include<stdio.h>
#include<math.h>
int a[3510];
void init()
{
	int i,j,k;
	for(a[0]=2,k=1,i=3;i*i<=1010000000;i++)
	{
		for(j=0;a[j]*a[j]<=i;j++)
		{
			if(i%a[j]==0) break;
		}
		if(a[j]*a[j]>i) a[k++]=i;
	}
}
int main()
{
	long n,i,sum,j;
	init();
	while(scanf("%ld",&n)&&n)
	{
		sum=1;
		for(i=0;n!=1&&a[i]*a[i]<=n;i++)
		{
			if(n%a[i]==0)
			{
				for(j=0;n%a[i]==0;n/=a[i],j++);
				sum*=a[i]-1;
				sum*=pow(a[i],j-1);
			}
		}
		if(n!=1) sum*=n-1;
		printf("%ld\n",sum);
	}
	return 0;
}