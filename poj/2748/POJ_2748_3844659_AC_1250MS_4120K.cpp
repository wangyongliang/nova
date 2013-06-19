#include<stdio.h>
int f[1000000];
int mod=100000;
int main()
{
	int n,i,j;
	f[1]=1;
	f[2]=2;
	for(i=3;i<1000000;i++)
	{
		f[i]=(f[i-1]*3-f[i-2]+mod)%mod;
	}
	scanf("%d",&i);
	while(i--) 
	{
		scanf("%d",&n);
		n%=750000;
		if(n==0) n=750000;
		printf("%d\n",f[n]);
	}
	return 0;
}