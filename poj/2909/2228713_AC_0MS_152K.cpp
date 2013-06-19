#include<stdio.h>
#include<math.h>
int a[32769];
void init()
{
	int i,j,k=1;
	for(i=0;i<32769;i++) a[i]=1;
	a[1]=0;
	for(i=2;i<=32769;i++)
	{
		if(a[i])
		{
			for(j=i+i;j<=32769;j+=i) a[j]=0;
		}
	}
}
int main()
{
	int i,count,n;
	init();
	while(scanf("%d",&n)&&n)
	{
		for(i=3,count=0;i<=n/2;i+=2)
		{
			if(a[i]&&a[n-i]) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}