#include<stdio.h>
#include<math.h>
#define max 1030
bool flag[1030]={0};
int a[200],k=0;
void init()
{
	int i,j;
	for(i=2;i<max;i++)
	{
		if(flag[i]==0)
		{
			a[k++]=i;
			for(j=i*i;j<max;j+=i) flag[j]=1;
		}
	}
}
__int64 f(int n)
{
	__int64 m=1;
	int i;
	for(i=1;i<=n;i++) m*=i;
	return m;
}
int ans1,ans2;
int main()
{
	int sum,n;
	__int64 m1,m2;
	int i,j,k;
	int b[100];
	init();
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		for(i=0;i<172;i++)
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
		m1=f(sum);
		for(i=0;i<k;i++)
		{
			m2=f(b[i]);
			m1/=m2;
		}
		printf("%d %I64d\n",sum,m1);
	}
	return 0;
}
