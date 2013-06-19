#include<stdio.h>
void main()

{
	int n,i,j,sum,k;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)break;
		else
		{
			sum=0;
			k=0;
			while(n--)
			{
				scanf("%d %d",&i,&j);
				sum+=(j-k)*i;
				k=j;
			}
			printf("%d miles\n",sum);
		}
	}
}