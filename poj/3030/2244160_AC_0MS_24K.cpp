#include<stdio.h>
int main()
{
	int n,m,l,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&l);
		if(n>m-l) printf("do not advertise\n");
		else if(n<m-l) printf("advertise\n");
		else printf("does not matter\n");
	}
	return 0;
}