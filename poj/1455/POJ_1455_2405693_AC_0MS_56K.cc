#include<stdio.h>
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(n/2)*((n-1)/2));
	}
	return 0;
}