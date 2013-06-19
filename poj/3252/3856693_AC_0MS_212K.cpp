#include<stdio.h>
long long c[32][32];
void init()
{
	c[1][1]=1;
	long long i,j;
	for(i=0;i<32;i++) c[i][0]=1;
	for(i=2;i<32;i++)
	{
		c[i][1]=i;
		for(j=2;j<=i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
long long ans;
long long cnt,flag[33];
void dfs(long long deep,long long n,long long m,long long zero,long long one)
{
	long long i,j;
	if(deep==cnt)
	{
		if(m==0) ans++;
		if(m&&zero>=one) ans++;
		return;
	}
	else
	{
		if(n>m)
		{
			if(m)
			{
				for(i=0;i<=cnt-deep;i++)
				{
					if(zero+i>=one+cnt-deep-i) ans+=c[cnt-deep][i];
				}
			}
			else
			{
				for(i=1;i<=cnt-deep;i++)
				{
					for(j=1;j<=i;j++)
					{
						if(i-j>=j) ans+=c[i-1][i-j];
					}
				}
			}
		}
		else
		{
			dfs(deep+1,n*2+flag[deep],m*2,zero+1,one);
			if(flag[deep]) dfs(deep+1,n*2+flag[deep],m*2+1,zero,one+1);
		}
	}
}
long long f(long long n)
{
	if(n<=1) return 1;
	ans=0;
	long long i,j=1;
	for(i=0;(j<<i)<=n;i++);
	cnt=i;
	for(;n;n/=2) flag[--i]=n%2;
	dfs(0,0,0,0,0);
	ans++;
	return ans;
	
}
int main()
{
	init();
	long long n,m;
	long long sum=1;
	while(scanf("%I64d%I64d",&n,&m)!=EOF)
	{
		printf("%I64d\n",f(m)-f(n-1));
	}
	return 0;
}