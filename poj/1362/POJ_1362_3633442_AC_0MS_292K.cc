#include<stdio.h>
int a[100];
int main()
{
	__int64 n,i,j,k;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		j=1;
		k=0;
		for(i=1;(j<<i)<=n;i++);
		printf("%I64d [",n);
		k=0;
		for(;n;i--)
		{
			j=1;
			j<<=i;
			j--;
			if(j*2==n) 
			{
				a[k]=a[k+1]=i,k+=2;
				n=0;
			}
			if(j<=n)
			{
				a[k++]=i;
				n-=j;
			}
		}
		i=0;
		for(k--;k>=0;k--) 
		{
			if(i) printf(",");
			i++;printf("%d",a[k]-1);
		}
		printf("]\n");
	}
	return 0;
}