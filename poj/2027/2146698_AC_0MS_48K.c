#include<stdio.h>
void main()
{
	int i,j,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&i,&j);
		if(i<j)
			printf("NO BRAINS\n");
		else
			printf("MMM BRAINS\n");
	}
}