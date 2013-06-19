#include<stdio.h>
int main()
{
	int k,i;
	__int64 n,m,sum;
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		scanf("%I64d%I64d",&n,&m);
		sum=n+m;
		n=n>m?n-m:m-n;
		n++;
		if(n%2==0) n/=2;
		else sum/=2;
		sum*=n;
		printf("Scenario #%d:\n%I64d\n\n",i,sum);
	}
	return 0;
}
