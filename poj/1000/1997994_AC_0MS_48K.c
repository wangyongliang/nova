#include<stdio.h>
void main()
{
	int a,b;
	while(EOF!=scanf("%d %d",&a,&b))
	{
		printf("%d",a+b);
	}
}