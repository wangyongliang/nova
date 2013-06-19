#include<stdio.h>
long long a[100010];//计算1到n去掉5的倍数，并且去掉相应2的倍数之后的乘积
long long mod=10; //求末尾x位，mod就等于10^x
long long dp[100010];
void init()
{
	long long i;
	dp[0]=a[0]=1;
	int flag=0;
	for(i=1;i<=mod;i++)
	{
		dp[i]=dp[i-1]*i;
		dp[i]%=mod;
		if(i%5)
		{
			a[i]=a[i-1]*i;
			a[i]%=mod;
		}
		else
		{
			if(i%2) a[i]=a[i-2]*((i-1)/2);
			else 
			{
				a[i]=a[i-3];
				a[i]*=(i-2)/2;
				a[i]%=mod;
				a[i]*=(i-1);
			}
			a[i]%=mod;
		}
	}
}
long long pow(long long a,long long b)
{
	long long tp=a,i;
	long long ans=1;
	for(i=1;i<=b;i*=2)
	{
		if(b&i)
		{
			ans*=tp;
			ans%=mod;
		}
		tp*=tp;
		tp%=mod;
	}
	return ans;
}


long long dfs(long long n)
{
	if(n<5) return dp[n];
	else
	{
		long long ans;
		ans=dfs(n/5);
		ans*=pow(a[mod],n/mod);
		ans%=mod;
		ans*=a[n%mod];
		return ans%mod;
	}

}


int main()
{
	init();
	long long n;
//	printf("%d\n",pow(2,7));
//  freopen("1.out","w",stdout);
	while(scanf("%I64d",&n)!=EOF)
//	for(n=1;n<=1000;n++)
	{
		printf("%5I64d -> %I64d\n",n,dfs(n));
	}
	return 0;
}