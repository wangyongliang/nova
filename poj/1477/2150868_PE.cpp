#include<stdio.h>
void main()
{
	int a[60],i,j,sum,n,k;
	k=0;
	while(scanf("%d",&n)&&n)
	{
		k++;
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sum/=n;
		for(j=i=0;i<n;i++)
		{
			if(a[i]>sum)
				j+=a[i]-sum;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n",k,j);
	}
}