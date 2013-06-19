#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[10000],pre[10000],p[10000];
int len,a[11];
int find(int x)
{
	int i,j;
	int flag,m;
	int n;
	if(dp[x]!=-1) return dp[x];
	pre[x]=-1;
	dp[x]=1;
	n=0;
	for(i=0;i<len;i++) 
	{
		if((1<<i)&x) n=n*10+a[i];
	}
	p[x]=n;
	for(i=0;i<(1<<len);i++)
	{
		if((i|x)==x)
		{
			m=0;
			for(j=0;j<len;j++)
			{
				if((1<<j)&i)
				{
					if(a[j]==0&&m==0) break;
					m=m*10+a[j];
				}
			}
			if(m>1&&j==len&&n%m==0&&n!=m)
			{
				j=find(i^x);
				if(dp[x]<j+1||(dp[x]==j+1&&p[pre[x]]>p[i^x]))
				{
					pre[x]=i^x;
					dp[x]=j+1;
				}
			}
		}
	}
	return dp[x];
}
void print(int x)
{
	int i;
	int m=0;
	for(i=0;i<len;i++)
	{
		if((1<<i)&x) m=m*10+a[i];
	}
	printf("%d ",m);
	if(pre[x]!=-1) print(pre[x]);

}
int main()
{
	int n,m;
	while(scanf("%d",&n)&&n)
	{
		for(m=0;m<10000;m++) dp[m]=pre[m]=-1;
		m=n;
		for(len=0;n;len++,n/=10) a[len]=n%10;
		reverse(a,a+len);
		find((1<<len)-1);
		print((1<<len)-1);
		printf("\n");
	}
	return 0;
}