#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		if(n==1||n==2) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}