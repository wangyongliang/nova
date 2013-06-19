#include<stdio.h>
int a[250][250];
void inti()
{
	int i,j;
	for(i=0;i<250;i++)
	{
		for(j=0;j<250;j++)
		{
			a[i][j]=0;
		}
	}
	a[0][0]=1;
	a[1][0]=3;
	for(i=2;i<250;i++)
	{
		for(j=0;j<250;j++)
		{
			a[i][j]=a[i-1][j]+2*a[i-2][j];
		}
		for(j=0;j<250;j++)
		{
			a[i][j+1]+=a[i][j]/10;
			a[i][j]%=10;
		}
	}
}
void main()
{
	int n,i;
	inti();
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			printf("1\n");
		else
		{
			for(i=249;!a[n-1][i];i--);
			for(;i>=0;i--)
			{
				printf("%d",a[n-1][i]);
			}
			printf("\n");
		}
	}
}