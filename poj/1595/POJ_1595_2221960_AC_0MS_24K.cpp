#include<stdio.h>
int main()
{
	int a[200]={1},i,j,n,c,k,flag=0;
	a[1]=2;
	for(i=3,n=2;i<1100;i++)
	{
		for(j=1;a[j]*a[j]<=i;j++)
		{
			if(i%a[j]==0) break;
		}
		if(i%a[j]) a[n++]=i;
	}
	while(scanf("%d%d",&n,&c)!=EOF)
	{

		for(i=0;a[i]<=n;i++);
		if(i&1)
		{
			j=(i-1)/2-c+1;
			k=(i-1)/2+c-1;
		}
		else
		{
			j=i/2-c;
			k=i/2+c-1;
		}
		if(j<0)j=0;
		if(k>i-1)k=i-1;
		printf("%d %d:",n,c);
		for(i=j;i<=k;i++)
			printf(" %d",a[i]);
		printf("\n");
		flag++;
		printf("\n");
	}
	return 0;
}
