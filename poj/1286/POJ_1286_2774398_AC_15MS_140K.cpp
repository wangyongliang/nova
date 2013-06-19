#include<stdio.h>
#include<string.h>
typedef __int64 int64;
#define max 11
#define big 1000000000000000
int64 ans[max];
void pow(int k,int c)
{
	int64 a[max]={0};
	a[0]=1;
	int i;
	while(k--)
	{
		for(i=0;i<10;i++) a[i]*=c;
		for(i=0;i<10;i++) a[i+1]+=a[i]/big,a[i]%=big;
	}
	for(i=0;i<10;i++)
	{
		ans[i]+=a[i];
		ans[i+1]+=ans[i]/big;
		ans[i]%=big;
	}
}
void div(int n)
{
	int i;
	__int64 mod=0;
	for(i=9;i>=0;i--)
	{
		mod=mod*big+ans[i];
		ans[i]=mod/n;
		mod%=n;
	}
}
void polya(int n,int c)//旋转和翻转都看作相同
{
	bool b1[52]={0},b2[52]={0};
	int i,j,k;
	int x,y;
	for(i=0;i<n;i++)
	{
		memset(b1,0,sizeof(b1));
		memset(b2,0,sizeof(b2));
		for(x=y=j=0;j<n;j++)
		{
			if(!b1[(i+j)%n])
			{
				for(x++,k=(i+j)%n;!b1[k];k=(i+k)%n) b1[k]=1;
			}
			if(!b2[n-1-(i+j)%n])
				for(y++,k=n-1-(i+j)%n;!b2[k];k=n-1-(i+k)%n) b2[k]=1;
		}
		pow(x,c);
		pow(y,c);
	}
	div(n*2);
}
int main()
{
	int n,c=3;
	int i;
	while(scanf("%d",&n)&&n!=-1)
	{
		c=3;
		if(c==0||n==0)
		{
			printf("0\n");
			continue;
		} 
		for(i=0;i<100;i++) ans[i]=0;
		polya(n,c);
		for(i=9;ans[i]==0&&i>=0;i--);
		if(i==0) printf("%I64d",ans[0]);
		else
		{
			printf("%I64d",ans[i]);
			for(i--;i>=0;i--) printf("%015I64d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}

