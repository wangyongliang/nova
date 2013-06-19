#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,p,t=1;
	char s[100];
	__int64 ans;
	while(scanf("%d%d",&p,&a)&&(a+p))
	{
		if(p<0) p=-p;
		ans=1;
		while(a)
		{
			ans*=(a%p+1);
			a/=p;
			ans%=10000;
		}
		printf("Case %d: %04I64d\n",t++,ans);
	}
	return 0;
}