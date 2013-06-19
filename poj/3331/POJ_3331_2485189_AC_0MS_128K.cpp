#include<stdio.h>
int a[1001];
void f(int n)
{
	int i;
	for(i=1;i<a[0];i++)
	{
		a[i]*=n;
	}
	for(i=1;i<a[0];i++)
	{
		if(a[i]/10)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
	if(a[i])
	{
		a[0]++;
		while(a[i]/10)
		{
			a[i+1]=a[i]/10;
			a[i]%=10;
			i++;
			a[0]++;
		}
	}
}
int main()
{
	int n,t;
	int m,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<1000;i++) a[i]=0;
		a[0]=2;
		a[1]=1;
		while(n>0)
		{
//			printf("%d\n",n);
			f(n);
			n--;
		}
		n=0;
		for(i=1;i<a[0];i++)
		{
//			printf("%d\n",i);
			if(a[i]==m) n++;
		}
		printf("%d\n",n);
	}
	return 0;
}