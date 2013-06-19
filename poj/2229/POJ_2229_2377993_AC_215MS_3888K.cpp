#include<stdio.h>
int n,a[1000010];
int main()
{
	int i;
	a[1]=1;
	a[2]=2;
	for(i=3;i<=1000002;i++)
	{
		if(i%2) a[i]=a[i-1];
		else a[i]=(a[i-2]+a[i/2])%1000000000;
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}