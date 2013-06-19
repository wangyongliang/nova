#include<stdio.h>
#define maxn 2010000
bool flag[maxn];
int main()
{
	int t;
	int a[10];
	int i,j;
	scanf("%d",&t);
	int cnt,max;
	while(t--)
	{
		for(i=0;i<1000010;i++) flag[i]=0;
		for(i=0;i<4;i++)
		{
			scanf("%d",&a[i]);
		}
		flag[0]=1;
		cnt=0;
		max=-1;
		for(i=0;i<=1000000;i++)
		{
			if(flag[i])
			{
				for(j=0;j<4;j++)
				{
					flag[i+a[j]]=1;
				}
			}
			else
			{
				cnt++;
				max=i;
			}
		}
		if(cnt>maxn/4) max=-1;
		printf("%d\n%d\n",cnt,max);
	}
	return 0;
}