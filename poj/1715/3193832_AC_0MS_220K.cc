#include<stdio.h>
typedef __int64 int64;
int a[10]={0};
int sum[10];
int f(int n,int k)
{
	int ans=1;
	int i=n;
	while(k--) ans*=i,i--;
	return ans;
}
int main()
{
	int i,j,k,t;
	for(i=1;i<=8;i++) a[i]=15*f(15,i-1);
	sum[9]=0;
	for(i=8;i>=1;i--) sum[i]=sum[i+1]+a[i];
	int n;
	int flag[20];
	int ans[20];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=8;sum[i]<n;i--);
		k=i;
		for(a[0]=16,j=1;j<i;j++) a[j]=a[j-1]-1;
		for(a[j]=1,j--;j>=0;j--) a[j]=a[j+1]*a[j];
		n=sum[i]-n; 
		for(i=0;i<20;i++) flag[i]=0;
		for(i=0;i<k;i++)
		{
			t=n/a[i+1]+1;
			n%=a[i+1];
			if(i==0) j=1;
			else j=0;
			for(;j<17&&t;j++)
			{
				if(flag[j]==0) t--;
			}
			flag[j-1]=1;
			ans[i]=j-1;
		}
		for(i=0;ans[i]==0;i++);
		for(;i<k;i++) printf("%X",ans[i]);
		printf("\n");
	}
	return 0;
}