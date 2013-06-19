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
void init(string str)
{
	int i,j;
	int n=str.size();
	for(i=0;i<n;i++)
	{
		for(j=0;j<10;j++) dp[i][j][0]=dp[i][j][1]=0;
	}
	for(i=0;i<=str[0]-'0';i++) dp[0][i][0]=1;
	for(;i<10;i++) dp[0][i][1]=1;
	sum[0][0]=dp[0][0][0];
	sum[0][1]=dp[0][0][1];
	for(i=1;i<10;i++) 
	{
		sum[i][0]=sum[i-1][0]+dp[0][i][0];
		sum[i][1]=sum[i-1][1]+dp[0][i][1];
	}
	for(i=1;i<str.size();i++)
	{
		for(j=0;j<10;j++)
		{
			if(j<str[i]-'0')
			{
				dp[i][j][0]+=sum[9][0]+sum[9][1];
				dp[i][j][1]+=0;
			}
			else if(j==str[i]-'0')
			{
				dp[i][j][0]+=sum[9][0];
				dp[i][j][1]+=sum[9][1];
			}
			else
			{
				dp[i][j][0]=0;
				dp[i][j][1]=sum[9][0]+sum[9][1];
			}
		}
		for(j=0;j<10;j++) 
		{
			sum[j][0]=dp[i][j][0];
			sum[j][1]=dp[i][j][1];
			if(j) 
			{
				sum[j][0]+=sum[j-1][0];
				sum[j][1]+=sum[j-1][1];
			}
		}
	}
}
long long getnum(long long n,long long m)
{
	string str1,str2;
	str1=itostring(n);
	str2=itostring(m);
	//	while(str2.size()<str1.size()) str2='0'+str2;
	int i,j,k,l;

	init(str1);
	long long ans=0;
	int num1=str1.size();
	int num2=str2.size();
	k=num1-1;
	long long tp[20][10][2]={0};
	for(i=0;i<str1.size();i++)
	{
		for(j=0;j<10;j++)
		{
			tp[i][j][0]=dp[i][j][0];
			tp[i][j][1]=dp[i][j][1];
			if(i) 
			{
				tp[i][j][0]+=tp[i-1][j][0];
				tp[i][j][1]+=tp[i-1][j][1];
			}
		}
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
				for(;j<str2[i]-'0';j++)	ans+=tp[k-1][j][0]+tp[k-1][j][1];
			}
		}
		else if(flag==0)
		{
			for(;j<str2[i]-'0';j++)
			{
				if(j<str1[k]-'0') ans+=tp[k][j][0]+tp[k][j][1];
				else if(j==str1[k]-'0')
				{
					ans+=tp[k][j][0];
					if(k) ans+=tp[k-1][j][1];
				}
				else
				{
					if(k) ans+=tp[k-1][j][0]+tp[k-1][j][1];
				}
			}
		}
		else
		{
			for(;j<str2[i]-'0';j++) ans+=tp[k][j][0]+tp[k][j][1];
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
	long long k,m;
	long long min,max,mid;
/*	while(cin>>k>>m)
	{
		cout<<getnum(k,m)<<endl;
	} */
	while(scanf("%I64d%I64d",&k,&m)!=EOF)
	{
		swap(k,m);
	//	printf("%I64d\n",getnum(k,m));
	//	continue;
		min=MAX(k,m);
		max=1;
		max=max<<61;
		long long ans=0;
	//	printf("%I64d\n",getnum(1831,25));
		while(min<max)
		{
			mid=(min+max)/2;
			if(getnum(mid,m)<k)
			{
				min=mid+1;
			}
			else
			{
				if(ans==0) ans=mid;
				if(ans>mid) ans=mid;
				max=mid;
			}
		}
		if(getnum(ans,m)==k)	printf("%I64d\n",ans);
		else printf("0\n");
	}
	return 0;
}
