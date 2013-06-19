#include<stdio.h>
long a[11];
long b[1024];
void init()
{
	int i,j,k,flag;
	for(i=2,a[0]=a[1]=1;a[i-1]*i<=1000000;a[i]=a[i-1]*i,i++);
	for(i=1,flag=1;i<1024;i++)
	{
		b[flag]=0;
		for(j=i,k=1;j;k++)
		{
			b[flag]+=(j%2)*a[k];
			j/=2;
		}
//		b[flag+1]=b[flag]+1;
		if(b[flag]!=b[flag-1]) flag++;
		b[flag]=b[flag-1]+1;
		flag++;
	}
}
int main()
{
	init();
	int i,j,mid;
	long n;
	while(scanf("%ld",&n)&&n>=0)
	{
		if(n==0) 
		{
			printf("NO\n");
			continue;
		}
		for(i=0;b[i]<=n;i++)
		{
			if(b[i]==n)
				break;
		}
		if(b[i]>n) printf("NO\n");
		else
			printf("YES\n");

	}
	return 0;	
}