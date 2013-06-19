#include<stdio.h>
void main()
{
	int t,k=0,i,n,sum,sun;
	scanf("%d",&t);
	while(k<t)
	{
		k++;
		sum=0;
		sun=1;
		scanf("%d",&n);
		for(i=2;i<=n+1;i++)
		{
			sun+=i;
			sum+=(i-1)*sun;
		}
		printf("%d %d %d\n",k,n,sum);
	}
}