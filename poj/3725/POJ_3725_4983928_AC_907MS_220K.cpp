#include<iostream>
#include<string >
#include<algorithm>
#define MIN(x,y) (x)>(y) ?(y):(x)
#define MAX(x,y) (x)>(y) ?(x):(y)

using namespace std;
long long dp[20][11][2];
long long sum[11][2];
string itostring(long long n)
{
	string str="";
	int i;
	while(n)
	{
		str=str+(char)(n%10+'0');
		n/=10;
	}
	return str;
}
long long bit[20];

long long getnum(long long n,long long m)
{
	string str1,str2;
	str1=itostring(n);
	str2=itostring(m);
	int i,j,k,l;
	long long ans=0;
	int num1=str1.size();
	int num2=str2.size();
	k=num1-1;
	long long dq[20]={0};
	dq[0]=1;
	dq[1]=str1[0]-'0'+1;
	ans=10;
	for(i=2;i<str1.size();i++,ans*=10)
	{
		dq[i]=dq[i-1]+(str1[i-1]-'0')*ans;
	}
	int flag=0;
	ans=0;
	for(i=str2.size()-1;i>=0;i--,k--)
	{
		if(i==str2.size()-1) j=1; //保证最高位不能为0
		else j=0;
		if(flag==1)
		{
			if(k) 
			{
				ans+=bit[k-1]*(str2[i]-'0'-j);
			}
		}
		else if(flag==0)
		{
			if(str1[k]<str2[i])
			{
				ans+=bit[k]*(str1[k]-'0'-j);
				ans+=dq[k];
				if(k) ans+=bit[k-1]*(str2[i]-str1[k]);
			}
			else ans+=bit[k]*(str2[i]-'0'-j);
		}
		else
		{
			ans+=bit[k]*(str2[i]-'0'-j);
		}
		if(flag==0)
		{
			if(str2[i]>str1[k]) flag=1;
			else if(str2[i]<str1[k]) flag=-1;
		}
	}
	return ans+str2.size();
}

int main()
{
	long long k,m,inf=1;
	long long min,max,mid;
	inf=190000000888888879;
	int i;
	bit[0]=1;
	for(i=1;i<20;i++) bit[i]=bit[i-1]*10+1;
	while(scanf("%I64d%I64d",&k,&m)!=EOF)
	{
		if(getnum(m,m)>k)
		{
			printf("0\n");
			continue;
		}
		min=MAX(k,m);
		max=min*10;
		while(max<inf)
		{
			if(getnum(max,m)>k) break;
			max*=10;
			min*=10;
		}
		long long ans=0;

		while(min<max)
		{
			mid=(min+max)/2;
			if(getnum(mid,m)<k)			min=mid+1;
			else	max=mid;
		}
		if(getnum(min,m)==k)	printf("%I64d\n",min);
		else printf("0\n");
	}
	return 0;
}

