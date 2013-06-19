#include<stdio.h>
#define big 10000000000
__int64 fact[52][110]={0};

__int64 ans[100];
void add(int i,int k)
{
	int j;
	for(j=0;j<100;j++)
	{
		ans[j]+=fact[i][j]*k;
	}
	for(j=0;j<100;j++) ans[j+1]+=ans[j]/big,ans[j]%=big;
}
int main()
{
	char ch;
	int n;
	int a[100];
	int i,j,flag=0;
	int cnt;
	fact[1][0]=1;
	for(i=2;i<51;i++)
	{
		for(j=0;j<100;j++) fact[i][j]=fact[i-1][j]*i;
		for(j=0;j<100;j++) fact[i][j+1]+=fact[i][j]/big,fact[i][j]%=big;
	}
	while(scanf("%c",&ch))
	{
		if(ch=='-') break;
		if(flag) printf(",");
		for(i=0;i<100;i++) ans[i]=0;
		ans[0]=1;
		scanf("%d,(",&n);
		for(i=0;i<n-1;i++) scanf("%d,",&a[i]);
		scanf("%d))",&a[i]);
		for(i=0;i<n;i++)
		{
			for(cnt=0,j=i+1;j<n;j++) cnt+=a[j]<a[i];
			add(n-i-1,cnt);
		}
		for(i=99;!ans[i];i--);
		printf("%I64d",ans[i]);
		for(i--;i>=0;i--) printf("%010I64d",ans[i]);
		getchar();
		flag++;
	}
	printf("\n");
	return 0;
}
