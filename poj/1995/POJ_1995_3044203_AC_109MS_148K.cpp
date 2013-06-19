#include<stdio.h>
int m;
int f(int a,int b)
{
	__int64 mod;
	if(b==0) return 1;
	else if(b==1) return a%m;
	else
	{
					mod=f(a,b/2);
			mod*=mod;
			mod%=m;
		if(b%2==1)  return (mod*a)%m;
		else return mod;
	}
}
int main()
{
	int t,h,a,b;
	int ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d%d",&m,&h);
		while(h--)
		{
			scanf("%d%d",&a,&b);
			ans+=f(a,b);
			ans%=m;
		}
		printf("%d\n",ans);
	}
	return 0;
}