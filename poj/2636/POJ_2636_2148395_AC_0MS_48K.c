#include<stdio.h>
void main()
{
	int i,sum,j,k,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&j);
		sum=1-j;
		while(j--)
		{
			scanf("%d",&k);
			sum+=k;
		}
		printf("%d\n",sum);
	}
}