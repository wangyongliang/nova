#include<stdio.h>
int a[1299]={0},b[1299]={0};
void init()
{
	int k,i,n,j;
	for(b[0]=a[0]=2,i=3,k=1;i*i<=101000000;i++)
	{
		for(j=0;a[j]*a[j]<=i&&i%a[j];j++);
		if(a[j]*a[j]>i) 
		{
			a[k++]=i;
			n=a[k-1];
			while(n)
			{
				b[k-1]+=n%10;
				n/=10;
			}
			
		}

	}
}

int main()
{
	long n,m,i;
	int j,sum1,sum2;
	init();
	while(scanf("%ld",&n)&&n)
	{

		for(i=n+1;;i++)
		{
			m=i;
			sum1=sum2=0;
			while(m)
			{
				sum1+=m%10;
				m/=10;
			}
			for(j=0,m=i;a[j]*a[j]<=m;j++)
			{
				if(m%a[j]==0)
				{
					while(m%a[j]==0)
					{
						sum2+=b[j];
						m/=a[j];
					}
				}
			}
			if(m!=1&&m!=i)
			{
				while(m)
				{
					sum2+=m%10;
					m/=10;
				}
			}
			if(sum1==sum2) break;
		}
		printf("%ld\n",i);
	}
	return 0;
}
