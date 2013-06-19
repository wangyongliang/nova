#include<stdio.h>
#define maxn 1000010
int flag[maxn][2];
int ans[maxn]={0};
void init()
{
	int i,j;
	int k;
	for(i=0;i<maxn;i++) flag[i][1]=i,flag[i][0]=0;
	for(i=5;i<maxn;i+=4)
	{
		ans[i]=ans[i-4];
		if(flag[i][0]==2) ans[i]++;
		if(flag[i][0]==0)
		{
			for(j=5;j*i<maxn;j+=4)
			{
				k=i*j;
				while(flag[k][1]%i==0)
				{
					flag[k][0]++;
					flag[k][1]/=i;
				}
			}
		}
	}
}
int main()
{
	int n;
	init();
	int i;
	for(i=25;i<maxn;i+=4)
	{
		if(ans[i]==0) 
		{
			printf("%d\n",i);getchar();
		}
	}
	while(scanf("%d",&n)&&n)
	{
		printf("%d %d\n",n,ans[n]);
	}
	return 0;
}
