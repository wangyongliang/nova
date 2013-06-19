#include<stdio.h>
int main()
{
	int n,i,j,sum=0,sum1,c,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum1=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&c);
			if(i^j&&c==3) 
				sum1++;
		}
		sum1>sum?sum=sum1,k=i:sum=sum;
	}
	printf("%d\n",k+1);
	return 0;
}