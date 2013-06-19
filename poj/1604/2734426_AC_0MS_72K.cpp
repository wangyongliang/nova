#include<stdio.h>
int b[10]= {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int a[10]={1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
int f(int n)
{
	int i,j;
	if(n<10) return b[n];
	i=f(n/5)*a[n%10]*6; 
	i%=10;
	j=n/5;
	if(j%4==0) j=4;
	else j=j%4;
	for(;j;j--)
	{
		if(i==2) i=6;
		else if (i==6)  i=8;
		else i/=2;
	}
	return i;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%5d -> %d\n",n,f(n));
	}
	return 0;
}