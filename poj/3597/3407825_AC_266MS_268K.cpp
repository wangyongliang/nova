#include<stdio.h>
unsigned __int64 a[50010],b[50010];
int main()
{
	int n,i,j;
	a[2]=1;
	b[2]=0;
	for(i=3;i<=5000;i++)
	{
		a[i]=b[i]=0;
		for(j=2;j<i;j++)
		{
			b[i]+=a[j]*a[i+1-j];
			a[i]+=a[j]*b[i+1-j];
		}
		a[i]+=b[i];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%I64u\n",a[n]);
	}
	return 0;
}