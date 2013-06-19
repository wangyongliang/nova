// luky.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>
int flag[1000000]={0};
int prime[100000],k;
void init()
{
	int i,j;
	k=1;
	prime[0]=2;
	for(i=3;i<1000000;i+=2)
	{
		if(flag[i]==0)
		{
			prime[k++]=i;
			if(i<10000)
			{
				for(j=i*i;j<1000000;j+=2*i) flag[j]=1;
			}
		}
	}
}
long long muti(long long a,long long b,long long c)
{
	long long i;
	long long ans=0,tp=a;
	for(i=1;i<=b;i<<=1)
	{
		if(b&i) ans=(ans+tp)%c;
		tp=(tp+tp)%c;
	}
	return ans;
}
long long pow(long long a,long long b,long long c)
{
	long long tp=a,ans=1;
	long long i=1;
	for(;i<=b;i<<=1)
	{
		if(b&i) ans=muti(ans,tp,c);
		tp=muti(tp,tp,c);
	}
	return ans;
}
long long a[50],b[50],m;
long long best,n;
void dfs(int deep,long long tp)
{
	//if(tp>best) return;
	if(deep==m)
	{
		if(pow(10,tp,n)==1) 
		{
			if(best)best=best>tp?tp:best;
			else best=tp;
		}
	}
	else
	{
		int i;
		long long tp1=1;
		for(i=0;i<=b[deep];i++)
		{
			dfs(deep+1,tp*tp1);
			tp1*=a[deep];
		}
	}
}
int main()
{
	int t=1,i;
	init();
	long long tp,tp1,tp2;
//	printf("%d\n",pow(10,343,1977326743));
	while(scanf("%I64d",&n)&&n)
	{
		int cnt=0;
		while(n%2==0)
		{
			n/=2;
			cnt++;
		}
		printf("Case %d: ",t++);
		if(cnt>3) printf("0\n");
		else
		{
			if(n%5==0) printf("0\n");
			else{
			n*=9;
			tp2=tp=n;
			for(i=0;i<k;i++)
			{
				tp1=prime[i];
				if(tp1*tp1>n) break;
				if(n%prime[i]==0)
				{
					tp-=tp/prime[i];
					while(n%prime[i]==0) n/=prime[i];
				}
			}
			if(n>1) tp-=tp/n;
			n=tp;
			m=0;
			best=0;
			for(i=0;i<k;i++)
			{
				tp=prime[i];
				if(tp*tp>n) break;
				if(n%prime[i]==0)
				{
					a[m]=prime[i];
					b[m]=0;
					while(n%prime[i]==0)
					{
						n/=prime[i];
						b[m]++;
					//	m++;
					}
					m++;
				}
			}
			if(n>1)
			{
				a[m]=n;
				b[m++]=1;
			}
			tp=1;
			n=tp2;
			dfs(0,tp);
			printf("%I64d\n",best);
			}
		}
	}
	return 0;
}
