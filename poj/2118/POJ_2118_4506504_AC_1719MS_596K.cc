#include<iostream>
using namespace std;
#define maxn 101
void copy(int a[maxn][maxn],int b[maxn][maxn],int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++) a[i][j]=b[i][j];
	}
}
int mod=10000;
void muti(int a[maxn][maxn],int b[maxn][maxn],int c[maxn][maxn],int size)
{
	int i,j,k;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			a[i][j]=0;
			for(k=0;k<size;k++)
			{
				a[i][j]+=b[i][k]*c[k][j];
				a[i][j]%=mod;
			}
			
		}
	}
}

int dp[2][maxn][maxn];
int b[maxn];
int a[maxn];
void init(int n)
{
	int i,j,k;
	//for(i=0i<)
	for(k=0;k<1;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) dp[k][i][j]=0;
			//dp[0][i][i]=1;
		}		
	}
	for(i=1;i<n;i++) dp[0][i][i-1]=1;
	for(i=0;i<n;i++) dp[0][i][n-1]=b[i];
}
int ans[maxn][maxn],tp[maxn][maxn];
int main()
{
	int k;
//	int a[10],b[10];
	int i,j,n;
	int flag;
//	freopen("test.out","w",stdout);
	while(scanf("%d",&k)&&k)
	{
		if(k==0) return 0;
		for(i=0;i<k;i++) cin>>a[i];
		for(i=k-1;i>=0;i--) cin>>b[i];
		init(k);
		cin>>n;		
		for(i=0;i<maxn;i++)
		{
			for(j=0;j<maxn;j++) ans[i][j]=0;
			ans[i][i]=1;
		}
		if(n<k) cout<<a[n]<<endl;
		else{
		n-=(k-1);
		flag=0;
		for(i=0;(1<<i)<=n;i++)
		{
			j=1<<i;
			if(n&j)
			{
				muti(tp,ans,dp[flag],k);
				copy(ans,tp,k);
			}
			if(i+1<32)
			{
				muti(dp[1-flag],dp[flag],dp[flag],k);
			}
			flag=1-flag;
		}
		int sum=0;
		for(i=0;i<k;i++)
		{
			sum+=a[i]*ans[i][k-1];
			sum%=mod;
		}
		cout<<sum<<endl;
		}
	}
	return 0;
}