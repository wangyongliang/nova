#include<stdio.h>
#include<math.h>
int f(__int64 n)
{
	double x,y;
	__int64 m,k;
	int i;
	if(n>=0)
	{
		x=log(n)/log(2);
		i=(int)x;
		i++;
		for(;i>=1;i--)
		{
			y=x/i;
			y=pow(2,y);
			m=(long)y;
			k=m+1;
			if(pow(m,i)==n||pow(k,i)==n) return i;
		}
	}
	else 
	{
		n=-n;
		x=log(n)/log(2);
		i=(int)x;
		if(i%2==0) i++;
		for(;i>=1;i-=2)
		{
			y=x/i;
			y=pow(2,y);
			m=(long)y;
			k=m+1;
			if(pow(m,i)==n||pow(k,i)==n) return i;
		}
	}
	return 1;
}
int main()
{
	__int64 n;
	while(scanf("%I64d",&n)&&n)
	{
		printf("%d\n",f(n));
	}
	return 0;
}