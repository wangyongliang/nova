#include<stdio.h>
void main()
{
	int i,j,k,l,sum,flag;
	while(1)
	{
		scanf("%d %d",&i,&j);
		if(i||j)
		{
			sum=0;				
			flag=0;
			while(j--)
			{
				scanf("%d %d",&k,&l);
				sum+=k-flag;
				flag=l+1;
			}
			sum+=i-flag+1;
			printf("%d\n",sum);
		}
		else
			break;
	}
}