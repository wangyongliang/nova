//pku 1455
#include<stdio.h>
int a[100];
int b[100];
int gcd(int n,int m)
{
	int b;
	b=(n%m+m)%m;
	while(b)
	{
		n=m;
		m=b;
		b=n%m;
	}
	return m;
}
int main()
{
	int n,m,i,j,mod;
	__int64 sum;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		else
		{
			printf("%d things taken %d at a time is ",n,m);
			if(n==m||m==0) printf("1 exactly.\n");
			else
			{
				for(i=0;i<m;i++) a[i]=n--;
				for(j=0;j<m;j++) b[j]=j+1;
				for(j=0;j<m;j++)
				{
					for(i=0;i<m&&b[j]!=1;i++)
					{
						mod=gcd(a[i],b[j]);
						if(mod!=1)
						{
							b[j]/=mod;
							a[i]/=mod;
						}
					}
				}
				for(sum=1,i=0;i<m;i++) 
				sum*=a[i];
			printf("%I64d exactly.\n",sum);
			}

		}
	}
}