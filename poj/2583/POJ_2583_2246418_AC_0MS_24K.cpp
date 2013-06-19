#include<stdio.h>
int main()
{
	int a,b,c,x1,x2;
	while(scanf("%d %d %d",&c,&x1,&x2)!=EOF)
	{
		a=(x2-2*x1+c)/2;
		b=x1-c-a;
		printf("%d %d %d\n",a*9+3*b+c,a*16+4*b+c,a*25+5*b+c);
	}
	return 0;
}
