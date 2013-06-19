#include<stdio.h>
#include<math.h>
//#include<time.h>
int  p;
bool flag[100000]={0};
int prime[100000],k=0;
void init()
{
	int n=100000,i,j;
	prime[k++]=2;
	for(i=2;i<n;i+=2) flag[i]=1;
	for(i=3;i*i<n;i+=2)
	{
		if(flag[i]==0)
		{
			prime[k++]=i;
			for(j=i*i;j<n;j+=i*2) flag[j]=1;
		}
	}
	for(;i<n;i++)
	{
		if(flag[i]==0) prime[k++]=i;
	}
}
int ouler(int n)
{
	int ans=n,i;
	for(i=0;i<k&&n>1;i++)
	{
		if(n%prime[i]==0)
		{
			ans-=ans/prime[i];
			while(n%prime[i]==0) n/=prime[i];
		}
	}
	if(n>1) ans-=ans/n;
	return ans%p;
}
int pow(int n,int k)
{
    int ret = 1,a=n%p;
    while (k)
    {
        if (k&1) ret = ret*a%p;
        a = a*a%p;
        k >>= 1;
    }
    return ret%p;
}
int a[20],b[20],q,res,m;
void dfs(int deep,int num)
{
	int tp1,tp2,tp3,i;
	if(deep==q)
	{
		tp1=ouler(m/num);
		tp2=pow(m,num-1);
		tp1*=tp2;
		tp1%=p;
		res+=tp1;
		res%=p;
	}
	else
	{
		dfs(deep+1,num);
		for(i=1;i<=b[deep];i++)
		{
			num*=a[deep];
			dfs(deep+1,num);
		}
	}
}
int main()
{
	int n,t,i,j;
	int mid;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		m=n;
		q=res=0;
		mid=(int)sqrt(n);
		mid++;
		for(i=0;i<20;i++) a[i]=b[i]=0;
		for(i=0;prime[i]<=mid&&n>1;i++)
		{
			if(n%prime[i]==0)
			{
				a[q]=prime[i];
				while(n%prime[i]==0)
				{
					b[q]++;
					n/=prime[i];
				}
				q++;
			}
		}
		if(n!=1) 
		{
			a[q]=n;b[q++]=1;
		}
		dfs(0,1);
		printf("%d\n",res);
	}
	return 0;
}