#include<stdio.h> //1238
#include<math.h>
int main()
{
	long n,i,j,sum;
	while(scanf("%ld",&n)&&n)
	{
		sum=1;
		if(n%2==0)
		{
			for(j=0;n%2==0;n/=2,j++);
			sum*=pow(2,j-1);
		}
		for(i=3;i*i<n;i+=2)
		{
			if(n%i==0)
			{
				for(j=0;n%i==0;n/=i,j++);
				sum*=(i-1)*pow(i,j-1);
			}
		}
		if(n!=1) sum*=n-1;
		printf("%ld\n",sum);
	}
	return 0;
}