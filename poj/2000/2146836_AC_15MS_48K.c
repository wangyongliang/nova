#include<stdio.h>
void main()
{
	int i,j,k;
	while(scanf("%d",&j)&&j)
	{
		k=0;
		for(i=1;i*(i+1)/2<=j;i++)
		{
			k+=i*i;
		}
		k-i*i;
		k+=(j-i*(i-1)/2)*i;;
		printf("%d %d\n",j,k);
	}
}