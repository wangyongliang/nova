#include<stdio.h>
#define maxn 20009
int a[maxn]={0};
void init()
{
	int i,j,t;
	t=1;
	a[1]=t++;
	for(i=2;i<maxn;i++)
	{
		if(a[i]==0)
		{
			for(j=i;j<maxn;j+=i) a[j]=t;
			t++;
		}
	}
}
int main()
{
	init();
	int i,j,max,n;
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			if(a[j]>a[max]) max=j;
		}
		printf("%d\n",max);
	}
	return 0;
}