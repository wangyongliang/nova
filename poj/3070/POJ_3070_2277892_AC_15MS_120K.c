#include<stdio.h>
int a[15002];
void init()
{
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2;i<=15001;i++)
	{
		a[i]=(a[i-1]+a[i-2])%10000;
	}
}
int main()
{
	__int64 l;
	init();
	while(scanf("%I64d",&l)&&l!=-1)
	{
		l%=15000;
		printf("%d\n",a[l]);
	}
	return 0;
}