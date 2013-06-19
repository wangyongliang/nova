#include<stdio.h>
#include<math.h>
int main()
{
	long n,m,sum,i,k;
	double x1,x2;
	while(scanf("%ld",&n)!=EOF)
	{
		x1=(sqrt(8*n+1)-1)/2;
		i=(long)x1;
		n*=2;
		for(m=1,sum=0;m<=i;m++)
		{
			if(n%m==0)
			{
				k=n/m;
				if((m%2==1&&k%2==0)||(m%2==0&&k%2==1)) sum++;
			}
		}
		printf("%ld\n",sum);
	}
}
