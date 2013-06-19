#include<iostream>
#include<string >
#include<algorithm>
using namespace std;

long long bit[20];
long long p[20];

long long getnum(long long n,long long m)
{
	int i,j,k,l;
	long long ans=0;
	int num1=0;
	int num2=0;
	int str1[20],str2[20];
	for(;n;n/=10) str1[num1++]=n%10;
	for(;m;m/=10) str2[num2++]=m%10;
	k=num1-1;
	long long dq[20]={0};
	dq[0]=1;
	dq[1]=str1[0]+1;
	ans=10;
	for(i=2;i<num1;i++,ans*=10)
	{
		dq[i]=dq[i-1]+str1[i-1]*ans;
	}
	int flag=0;
	ans=0;
	for(i=num2-1;i>=0;i--,k--)
	{
		if(i==num2-1) j=1; //保证最高位不能为0
		else j=0;
		if(flag==1)
		{
			if(k) 
			{
				ans+=bit[k-1]*(str2[i]-j);
			}
		}
		else if(flag==0)
		{
			if(str1[k]<str2[i])
			{
				ans+=bit[k]*(str1[k]-j);
				ans+=dq[k];
				if(k) ans+=bit[k-1]*(str2[i]-str1[k]);
			}
			else ans+=bit[k]*(str2[i]-j);
		}
		else
		{
			ans+=bit[k]*(str2[i]-j);
		}
		if(flag==0)
		{
			if(str2[i]>str1[k]) flag=1;
			else if(str2[i]<str1[k]) flag=-1;
		}
	}
	return ans+num2;
}

int main()
{
	long long k,m,ans;
	int i;
	p[0]=bit[0]=1;
	for(i=1;i<20;i++) {
		bit[i]=bit[i-1]*10+1;
		p[i]=p[i-1]*10;
	}
	while(scanf("%I64d%I64d",&k,&m)!=EOF)
	{
		for(i=0;p[i]<=m;i++) ;
		if(m==p[i-1])
		{
			if(k==i) printf("%I64d\n",m);
			else printf("0\n",0);
			continue;
		}
		k-=getnum(m,m);
		if(k<0) printf("0\n");
		else if(k==0) printf("%I64d\n",m);
		else{
			for(m*=10;k>0;m*=10,i++)
			{
				if(k>m-p[i]) k-=m-p[i];
				else{
					ans=p[i]+k-1;
					k=-1;
				}
			}
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
