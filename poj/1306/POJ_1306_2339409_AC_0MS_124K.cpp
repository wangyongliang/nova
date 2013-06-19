//pku 1455
#include<stdio.h>
__int64  a[101][101];
__int64 combine(__int64 n,__int64 m)
{
	if(m>n||m<0|n<0)return 0;
	if(!a[n][m])
	{
		if(n==m||m==0) a[n][m]=1;
		else
		{
			if(!a[n-1][m]) a[n-1][m]=combine(n-1,m);
			if(!a[n-1][m-1]) a[n-1][m-1]=combine(n-1,m-1);
			a[n][m]=a[n-1][m]+a[n-1][m-1];
		}
	}
	return a[n][m];
}
int main()
{
	__int64 n,m;
	for(n=0;n<101;n++)
		for(m=0;m<101;m++) a[n][m]=0;
	while(scanf("%I64d%I64d",&n,&m)&&(n||m))
	{		
		printf("%I64d things taken %I64d at a time is %I64d exactly.\n",n,m,combine(n,m));
	}
}
