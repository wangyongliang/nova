#include<stdio.h>
int main()
{
	double l;
	int n,i,j; 
	printf("Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF)
	{
		
		if(n==1) printf("    1     0.500\n");
		else
		{
			i=2;
			j=2;
			l=0.5;
			for(;i<=n;i++)
			{
				l+=0.5/i;
			}
			printf("%5d %9.3lf\n",n,l);
		}
	}
	return 0;
}