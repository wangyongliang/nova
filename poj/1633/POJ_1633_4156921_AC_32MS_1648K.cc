#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 110
struct bignum
{
	int len;
	int a[maxn];
};
bignum itobignum(int n)
{
	bignum tp;
	int i;
	for(i=0;i<maxn;i++) tp.a[i]=0;
	for(i=0;n;i++,n/=10) tp.a[i]=n%10;
	if(i==0) 
	{
		tp.a[0]=0;
		tp.len=1;
	}
	else tp.len=i;
	return tp;
}
bignum stobignum(char s[])
{
	bignum tp;
	int i,j;
	for(i=0;s[i]=='0';i++) ;
	for(j=0;j<maxn;j++) tp.a[j]=0;
	if(i<0) tp.len=1;
	else
	{
		tp.len=strlen(s)-i;
		for(j=tp.len-1;s[i];i++,j--) tp.a[j]=s[i]-'0';
	}
	return tp;
}
int cmp(bignum tp1,bignum tp2)
{
	if(tp1.len>tp2.len) return 1;
	else if(tp1.len<tp2.len) return -1;
	else
	{
		for(int i=tp1.len-1;i>=0;i--)
		{
			if(tp1.a[i]>tp2.a[i]) return 1;
			if(tp1.a[i]<tp2.a[i]) return -1;
		}
		return 0;
	}
}
bignum add(bignum tp1,bignum tp2)
{
	bignum tp;
	int i;
	for(i=0;i<maxn;i++) tp.a[i]=0;
	for(i=0;i<tp1.len||i<tp2.len;i++)
	{
		tp.a[i]=0;
		if(i<tp1.len) tp.a[i]+=tp1.a[i];
		if(i<tp2.len) tp.a[i]+=tp2.a[i];
	}
	for(i=0;i<maxn-1;i++) 
	{
		tp.a[i+1]+=tp.a[i]/10;
		tp.a[i]%=10;
	}
	for(i=maxn-1;i>=0&&tp.a[i]==0;i--);
	if(i==0) tp.len=1;
	else tp.len=i+1;
	return tp;
}
bignum mun(bignum tp1,bignum tp2)
{
	bignum tp;
	int i;
	for(i=0;i<maxn;i++) tp.a[i]=0;
	for(i=0;i<maxn-1;i++)
	{
		if(tp1.a[i]>=tp2.a[i]) tp.a[i]=tp1.a[i]-tp2.a[i];
		else
		{
			tp1.a[i+1]--;
			tp.a[i]=tp1.a[i]+10-tp2.a[i];
		}
	}
	for(i=maxn-1;tp.a[i]==0&&i>=0;i--);
	if(i<0) tp.len=1;
	else tp.len=i+1;
	return tp;
}
bignum muti(bignum tp1,bignum tp2)
{
	bignum tp;
	int i,j;
	for(i=0;i<maxn;i++) tp.a[i]=0;
	for(i=0;i<tp1.len;i++)
	{
		for(j=0;j<tp2.len;j++)
		{
			tp.a[i+j]+=tp1.a[i]*tp2.a[j];
		}
	}
	for(i=0;i<maxn-1;i++)
	{
		tp.a[i+1]+=tp.a[i]/10;
		tp.a[i]%=10;
	}
	for(i=maxn-1;i>=0&&tp.a[i]==0;i--);
	if(i<0) tp.len=1;
	else tp.len=i+1;
	return tp;
}
void print(bignum tp)
{
	int i;
	for(i=tp.len-1;i>=0;i--) 
		printf("%d",tp.a[i]);
	printf("\n");
}
bignum dp[60][60];
int main()
{
	int t;
	int i,j;
	for(i=0;i<51;i++)
	{
		for(j=0;j<51;j++) dp[i][j]=itobignum(0);
	}
	dp[1][1]=itobignum(1);
	for(i=2;i<=50;i++)
	{
		dp[i][0]=itobignum(0);
		dp[i][1]=itobignum(1);
		for(j=2;j<=i;j++)
		{
			dp[i][j]=add( muti(dp[i-1][j],itobignum(j)) , muti(dp[i-1][j-1],itobignum(2*i-j)));
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&i,&j);
		print(dp[i][j]);
	}
	
	return 0;
}