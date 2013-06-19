#include<stdio.h>
int main()
{
	double l;
	int n,i; 
	printf("Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF)
	{
		l=0;
			for(i=1;i<=n;i++)
			{
				l+=0.5/i;
			}
			printf("%5d %9.3lf\n",n,l);
		
	}
	return 0;
}