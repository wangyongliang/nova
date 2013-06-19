#include<stdio.h>
int abs(int x)
{
	return x>0?x:-x;
}
int main()
{
	int n,m,p;
	while(scanf("%d%d%d",&n,&m,&p)&&(n+m+p))
	{
		if(n==p) 
		{
			printf("0\n");
			continue;
		}
		if(m==0) printf("No accounting tablet\n");
		else
		{
			n=abs(n-p);
			if(n%m) printf("No accounting tablet\n");
			else 
			{
				n/=m;
				printf("%d\n",n/3+(n%3!=0));
			}
		}
	}
	return 0;
}