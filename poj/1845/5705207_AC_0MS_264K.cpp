/*
ID: 05272021
LANG: C++
PROG:
*/
/*crackerwang*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define ABS(X)   ((x)>0?(x):-(x))
#define ps system("pause")
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef __int64 int64;
int64 mod=9901;
int64 f(int64 a,int64 b)
{
	int64 tp=a;
	int64 ans=1;
	for(int i=0;(1<<i)<=b;i++)
	{
		if((1<<i)&b)
		{
			ans=ans*tp;
			ans%=mod;
		}
		tp*=tp;
		tp%=mod;
	}
	return ans;
}

int64 g(int64 a,int64 b)
{
	if(b==0)
	{
		return 0;		
	}
	else 
	{
		int64 tp=g(a,b/2);

		int64 ans=tp+tp*f(a,b/2);
		ans%=mod;
		if(b&1) ans+=f(a,b);
		
		ans%=mod;
		
		return ans;		
	}
	
}

bool flag[10000]={0};
vector<int> prime;
void init()
{
	int i,j;
	prime.clear();
	for(i=2;i<10000;i++)
	{
		if(flag[i]==0)
		{
			prime.push_back(i);
			for(j=i;j<10000;j+=i) flag[j]=1;
		}
	}
}
int main()
{
	init();
	int64 a,b;
	int64 ans;
	int i;
	while(cin>>a>>b)
	{
//		cout<<g(a,b)<<endl;
	//	continue;
		ans=1;
		for(i=0;prime[i]*prime[i]<=a;i++)
		{
			if(a%prime[i]==0)
			{
				int64 cnt=0;
				while(a%prime[i]==0)				
				{
					a/=prime[i];
					cnt++;
				}
				cnt*=b;
				ans*=(g((int64)prime[i],cnt)+1);
				ans%=mod;
			}
		}
		if(a>1)
		{
			int64 cnt=0;
			ans*=(g(a,b)+1);
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
