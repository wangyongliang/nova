#include<stdio.h>
int main()
{
	int t,n,i,a,b,c,j,sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=100000000;
		scanf("%d",&n);
		for(i=1;i*i*i<=n;i++)
		{
			if(n%i==0)
			{
				for(j=1;j*j<=n/i;j++)
				{
					a=n/i;
					if(a%j==0)
					{
						a=n/i/j;
						sum=2*a*i+2*i*j+2*a*j<sum?2*a*i+2*i*j+2*a*j:sum;
					}
				}
			}
		}
		printf("%d\n",sum);
	}
}