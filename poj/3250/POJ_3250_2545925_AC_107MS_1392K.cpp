#include<stdio.h>
#define maxn 80009
__int64 a[maxn][2];
int main()
{
	int n,i,j,head;
	__int64 sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=head=0;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a[head][0]);
			a[head][1]=i;
			while(head>0&&a[head][0]>=a[head-1][0])
			{
				sum+=a[head][1]-a[head-1][1]-1;
				a[head-1][0]=a[head][0];
				a[head-1][1]=a[head][1];
				head--;
			}
			head++;
		}
		head--;
		for(i=0;i<head;i++)
		{
			sum+=a[head][1]-a[i][1];
		}
		printf("%I64d\n",sum);
	}
	return 0;
}
