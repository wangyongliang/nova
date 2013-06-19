#include<stdio.h>
void main()
{
	int n,m,k;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d:%d",&n,&m);
		if(m) printf("0\n");
		else
			printf("%d\n",(n+12)%24?(n+12)%24:24);
	}
}