#include<stdio.h>
int b[100000];
int c[100000];
bool flag[10000000];
int main()
{
	int a[300];
	int n,i,j;
	int t;
	int max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			max=max<a[i]?a[i]:max;
		}
		for(i=0;i<=max;i++) flag[i]=0;
		int k=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j]) b[k++]=a[i]-a[j];
				else b[k++]=a[j]-a[i];
			}
		}
		for(i=0;i<k;i++)
		{
			for(j=1;j*j<=b[i];j++)
			{
				if(b[i]%j==0)
				{
					flag[j]=flag[b[i]/j]=1;
				}
			}
		}
		for(i=1;i<=max;i++)
		{
			if(flag[i]==0) break;
		}
		printf("%d\n",i);
	}
	return 0;
}
