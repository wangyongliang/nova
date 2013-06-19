#include<stdio.h>
#include<math.h>
int sum;
long a[256],n;
void find(int n,int k,int j)
{
	int i;
	if(n==0||k==0)
	{
		if(n==0)
		{
			sum++;
			return;
		}
		else
			return;
	}
	else
	{
		i=(int)sqrt(n)-1>j?j:(int)sqrt(n)-1;
		for(;i>=0;i--)
		{
			if(a[i]*k<n)
				return;
			else
			{
				find(n-a[i],k-1,i);
			}
		}
	}
}
void main()
{
	int i;
	for(i=0;i<256;i++)
		a[i]=(i+1)*(i+1);
	while(scanf("%d",&n)&&n!=0)
	{
		sum=0;
		find(n,4,256);
		printf("%d\n",sum);
	}
}