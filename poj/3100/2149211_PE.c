#include<stdio.h>
#include<math.h>
void main()
{
	long n,max,i;
	double diff,maxdiff;
	int j;
	while(scanf("%ld %d",&n,&j))
	{
		if(n==0&&j==0)
			break;
		else if(n==0&&j!=0)
			printf("0\n");
		else
		{
			if(j==1)
				printf("%ld",n);
			else
			{
				for(i=1;pow(i,j)<=n;i++);
				max=pow(i,j)-n>n-pow(i-1,j)?i-1:i;
				printf("%d\n",max);
			}
		}
	}
}