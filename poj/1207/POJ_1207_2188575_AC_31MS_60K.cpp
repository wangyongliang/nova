#include<stdio.h>
int ma(int n)
{
	int j=0;
	while(n!=1)
	{
		if(n%2==0)
			n/=2;
		else
			n=n*3+1;
		j++;
	}
	return j;
}
void main()
{
	int i,j,n,max,l;
	while(scanf("%d %d",&i,&j)!=EOF)
	{
		max=0;
		if(i<j)
		{
			for(n=i;n<=j;n++)
		{
			l=ma(n);
			max=max>l?max:l;
		}
		printf("%d %d %d\n",i,j,max+1);
		}
		else
		{
						for(n=j;n<=i;n++)
		{
			l=ma(n);
			max=max>l?max:l;
		}
		printf("%d %d %d\n",i,j,max+1);
		}
	}
}