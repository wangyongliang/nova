#include<stdio.h>
void main()
{
	double i,j,k;
	while(scanf("%lf %lf %lf",&i,&j,&k)!=EOF)
	{
		while(k--)
		{
			j*=(100+i)/100;
		}
		printf("%d\n",(int)j);
	}
}