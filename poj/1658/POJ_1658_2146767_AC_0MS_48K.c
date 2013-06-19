#include<stdio.h>
void main()
{
	int i,j,k,l,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d",&i,&j,&k,&l);
		if(i+l==j+k)
			printf("%d %d %d %d %d\n",i,j,k,l,j+l-i);
		else
			printf("%d %d %d %d %d\n",i,j,k,l,j/i*l);
	}
}