#include<stdio.h>
int  main()
{
	int n;
	int i,j,sum,k;
	while(scanf("%d",&n)!=EOF)
	{
		sum=n;
		for(i=0;sum;)
		{
			i+=sum/5;
			sum/=5;
		}
		for(sum=j=1;j<=n;j++)
		{
			k=j;
			if(k%2==0&&i)
			{
				while(k%2==0&&i)
				{
					k/=2;
					i--;
				}
			}
			while(k%5==0) k/=5;
			sum*=k;
			sum%=10;
		}
		printf("%5d -> %d\n",n,sum);
	}
	return 0;
}