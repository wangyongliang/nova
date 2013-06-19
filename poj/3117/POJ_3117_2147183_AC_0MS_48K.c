#include<stdio.h>
void main()
{
	int t,n,i,j;
	while(1)
	{
		scanf("%d %d",&t,&n);
		if(!t)break;
		j=3*n;
		while(t--)
		{
			scanf("%*s %d",&i);
			j-=i;
		}
		printf("%d\n",j);
	}
}
