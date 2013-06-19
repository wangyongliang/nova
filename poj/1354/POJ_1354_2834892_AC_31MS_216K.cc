#include<stdio.h>
#define big  10000000000000000LL
typedef __int64 int64;
int64 ans[25];
void f(int n)
{
	int i;
	for(i=0;i<25;i++) ans[i]*=n;
	for(i=0;i<25;i++) ans[i+1]+=ans[i]/big,ans[i]%=big;
}
int main()
{
	int n;
	int i;
	while(scanf("%d",&n)&&n!=-1)
	{
		printf("N=%d:\n",n);
		for(i=0;i<24;i++) ans[i]=0;
		ans[0]=2;
		n--;
		while(n>1)
		{
			f(n);
			n--;
		}
		for(i=24;i>=0&&!ans[i];i--);
		printf("%I64d",ans[i]);
		for(i--;i>=0;i--)
		{
			printf("%016I64d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}