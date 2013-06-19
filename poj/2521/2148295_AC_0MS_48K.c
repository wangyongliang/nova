#include<stdio.h>
void main()
{
	int i,j,k,l;
	while(1)
	{
		scanf("%d %d %d %d",&i,&j,&k,&l);
		if(i||j||k||l)
		{
			j-=k;
			j-=i;
			printf("%d\n",-j);
		}
		else
			break;
	}
}