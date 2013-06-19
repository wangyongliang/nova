#include<stdio.h>
#define maxn 100100
int a[maxn];
__int64 sum[maxn];
int stack[maxn];
int left[maxn],right[maxn];
__int64 ans[maxn];
int main()
{
	int n,i,j;
	int max;
	while(scanf("%d",&n)!=EOF)
	{
		a[0]=-1;
		sum[0]=0;
		scanf("%d",&a[1]);
		sum[1]=a[1];
		for(i=2;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		a[n+1]=-1;
		stack[0]=0;
		int top=1;
		for(i=1;i<=n;i++)
		{
			while(a[stack[top-1]]>=a[i]) top--;
			left[i]=stack[top-1];
			stack[top++]=i;
		}
		stack[0]=n+1;
		top=1;
		for(i=n;i>=0;i--)
		{
			while(top>0&&a[stack[top-1]]>=a[i]) top--;
			right[i]=stack[top-1];
			stack[top++]=i;
		}
		max=1;
		for(i=1;i<=n;i++)
		{
			ans[i]=(sum[right[i]-1]-sum[left[i]])*a[i];
			if(ans[i]>ans[max]) max=i;
		}
		printf("%I64d\n%d %d\n",ans[max],left[max]+1,right[max]-1);
	}
	return 0;
}