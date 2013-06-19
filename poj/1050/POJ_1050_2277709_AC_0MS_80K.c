#include<stdio.h>
int n,a[101][101];
int max(int a[])
{
	int i,max,j;
	max=j=0;
	for(i=0;i<n;i++)
	{
		j+=a[i];
		if(j<0)j=0;
		else
		{
			max=max<j?j:max;
		}
	}
	return max;
}
int main()
{
	int i,j,b[100],k,max2;
	while(scanf("%d",&n)!=EOF)
	{
		max2=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)scanf("%d",&a[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) b[j]=a[i][j];
			for(j=i+1;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					b[k]+=a[j][k];
				}
				k=max(b);
				max2=max2<k?k:max2;
			}
		}
		printf("%d\n",max2);
	}
}