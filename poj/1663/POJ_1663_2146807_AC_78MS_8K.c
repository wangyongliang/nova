#include<stdio.h>
int find(int n)
{
	int i,k=0;
	if(n==0)
		return 0;
	for(i=1;i<=n;i++)
	{
		if(i&1)
			k++;
		else
			k+=3;
	}
	return k;
}
void main()
{
	int x,y,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&x,&y);
		if(x==y)
			printf("%d\n",find(x));
		else if(x-y==2)printf("%d\n",find(y)+2);
		else printf("No Number\n");
	}
}