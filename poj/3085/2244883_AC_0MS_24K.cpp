#include<stdio.h>
int main()
{
	int n,a[4]={25,10,5,1},i,money;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&money);
		printf("%d %d QUARTER(S),",i,money/a[0]);
		money%=a[0];
		printf(" %d DIME(S),",money/a[1]);
		money%=a[1];
		printf(" %d NICKEL(S),",money/a[2]);
		money%=a[2];
		printf(" %d PENNY(S)\n",money);
	}
	return 0;
}