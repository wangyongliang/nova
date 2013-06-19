#include<stdio.h>
int a[1000];
int gcd(int x,int y)
{
	int m;
	if(x<y)
	{
		m=x;
		x=y;
		y=m;
	}
	while(x%y!=0)
	{
		m=x%y;
		x=y;
		y=m;
	}
	return y;
}
void init()
{
	int i,j,k;
	a[0]=0;
	for(i=1;i<1000;i++)
	{
		a[i]+=a[i-1];
		for(j=1;j<=i+1;j++)
		{
			if(gcd(i+1,j)==1)a[i]+=2;
		}
	}
}
void main()
{
	init();
	int t,n,i=0;
	scanf("%d",&t);
	while(i<t)
	{
		i++;
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,a[n-1]+3);
	}
}