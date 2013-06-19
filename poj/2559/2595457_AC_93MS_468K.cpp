#include<stdio.h>
#define maxn 100009
typedef __int64 int64;
int64 a[maxn][2];
int main()
{
	int n;
	int64 max,tmp,temp;
	int i,j,head;
	while(scanf("%d",&n)&&n)
	{
		head=0;
		max=0;
		scanf("%I64d",a[0]);
		for(i=1;i<n;i++)
		{
			scanf("%I64d",&temp);
			if(temp>=a[head][0])
			{
				a[++head][0]=temp;
				a[head][1]=i;
			}
			else
			{
				j=head;
				while(head>0&&a[head][0]>=a[head-1][0]&&a[head][0]>temp)
				{
					tmp=(i-a[head][1])*a[head][0];
					max=max<tmp?tmp:max;
					head--;
				}
				tmp=(i-a[head][1])*a[head][0];
				if(max<tmp) max=tmp;
				if(a[head][0]<temp) a[++head][0]=temp;
				else
				{
					tmp=(i-a[head][1])*a[head][0];
					if(max<tmp) max=tmp;
					a[head][0]=temp;
				}
			}
		}
		for(i=0;i<=head;i++)
		{
			tmp=(n-a[i][1])*a[i][0];
			if(max<tmp) max=tmp;
		}
		printf("%I64d\n",max);
	}
	return 0;
}