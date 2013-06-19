#include<stdio.h>
#include<math.h>
#define max 1030
bool flag[1030]={0};
int a[200],k=0;
__int64 f[21];
void init()
{
	int i,j;
	for(i=2;i<max;i+=2) flag[i]=1;
	a[k++]=2;
	for(i=3;i<max;i+=2)
	{
		if(flag[i]==0)
		{
			a[k++]=i;
			for(j=i*i;j<max;j+=2*i) flag[j]=1;
		}
	}
	f[0]=1;
	for(i=1;i<=20;i++) f[i]=f[i-1]*i;
}

int ans1,ans2;
int main()
{
	int sum,n;
	__int64 m1,m2;
	int i,j;
	int b[100];
	init();
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		for(i=0;i<172&&a[i]*a[i]<=n;i++)
		{
			if(n==1) break;
			if(n%a[i]==0)
			{
				b[k]=0;
				while(n%a[i]==0)
				{
					b[k]++;
					n/=a[i];
				}
				k++;
			}
		}
		if(n!=1)  b[k++]=1;
		sum=0;
		for(i=0;i<k;i++) sum+=b[i];
		m1=f[sum];
		for(i=0;i<k;i++)
		{
			m2=f[b[i]];
			m1/=m2;
		}
		printf("%d %I64d\n",sum,m1);
	}
	return 0;
}

