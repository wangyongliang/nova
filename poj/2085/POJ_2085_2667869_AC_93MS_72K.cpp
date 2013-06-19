#include<stdio.h>
typedef __int64 int64;
int main()
{
	unsigned long n,m,sum;
	int i,j,k;
	while(scanf("%u%u",&n,&m)!=EOF)
	{
		if(n==-1&&m==-1) break ;
		k=1;
		for(i=1;i<=n;i++)
		{
			sum=(n-i)*(n-i-1)/2;
			if(sum>=m)
			{
				printf("%d ",i);
			}
			else
			{
				m=m-sum+i;
				printf("%d ",m);
				break;
			}
		}
		for(j=n;j>=i;j--)
		{
			if(j==m) continue;
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}

