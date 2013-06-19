#include<stdio.h>
int a[1000006]={0};
void init()
{
	int i,j;
	for(i=2;i<1000006;i++)
	{
		if(!a[i])
		{
			for(j=i*2;j<1000006;j+=i) a[j]=1;
		}
	}
}
int main()
{
	int n,i;
	init();
	while(scanf("%d",&n)&&n)
	{
		for(i=3;i<=n/2;i++)
		{
			if(!a[i]&&!a[n-i]) 
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
}
