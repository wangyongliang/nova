#include<stdio.h>
#define max 1000019
__int64  a[max]={0}, b[max]={0};
void init()
{
	int i,j,k,l;
	b[1]=0;
	for(i=2;i<max;i++)
	{
		if(!a[i])
		{
			b[i]=b[i-1]+i-1;
			for(j=2;j*i<max;j++)
			{
				k=j;
				l=1;
				while(k%i==0)
				{
					k/=i;
					l*=i;
				}
				l*=i-1;
				if(a[i*j]==0) a[i*j]=1;
				a[i*j]*=l;
			}
		}
		else b[i]=b[i-1]+a[i];
	}
}

int main()
{

	init();
	int n;
	while(scanf("%d",&n)&&n)
	{
		printf("%I64d\n",b[n]);
	}
	return 0;
}