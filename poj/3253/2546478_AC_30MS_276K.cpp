#include<stdio.h>
#define maxn 20009
#define inf 9999999999999
typedef __int64 int64;
int64 a[maxn];
int n;
void shiftdown(int k)
{
	int i,j;
	int64 temp;
	temp=a[k];
	i=k;
	j=i*2;
	while(j<n)
	{
		if(j+1<n&&a[j+1]<a[j]) j++;
		if(temp>a[j])
		{
			a[i]=a[j];
			i=j;
			j*=2;
		}
		else break;
	}
	a[i]=temp;
}
int main()
{
	int i,j;
	int64 sum;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++) scanf("%d",a+i);
		n++;
		for(j=n/2;j>0;j--) shiftdown(j);
		j=n-1;
		sum=0;
		while(--j)
		{
			if(a[2]>a[3]) i=3;
			else i=2;
			sum+=a[1]+a[i];
			a[1]+=a[i];
			a[i]=inf;
			shiftdown(i);
			shiftdown(1);
		}
		printf("%I64d\n",sum);
	}
	return 0;
}