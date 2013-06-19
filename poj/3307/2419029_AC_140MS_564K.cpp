#include<stdio.h>
__int64 a[66666];
int f[4]={6,4,3,2};
int c[4]={2,3,5,7};
int main()
{
	int i,j,n,min,t;
	for(i=1;i<=10;i++) a[i]=i;
	for(;i<66666;i++)
	{
		min=0;
		for(j=0;j<4;j++)
		{
			if(a[f[min]]*c[min]>a[f[j]]*c[j]) min=j;
		}
		a[i]=a[f[min]]*c[min];
		f[min]++;
		for(j=0;j<4;j++)
		{
			if(a[f[j]]*c[j]==a[f[min]-1]*c[min]) f[j]++;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%I64d\n",a[n]);
	}
	return 0;
}
