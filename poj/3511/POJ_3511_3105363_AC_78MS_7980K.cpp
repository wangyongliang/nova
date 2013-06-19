#include<stdio.h>
#define maxn 1000000+10
int flag[maxn]={0};
int cnt[maxn]={0};
void init()
{
	int i,j;
	for(i=2;i<maxn;i++)
	{
		if(flag[i]==0)
		{
			for(j=i*2;j<maxn;j+=i) flag[j]=1;
		}
	}
	for(i=0;i<2;i++) flag[i]=cnt[i]=0;
	flag[2]=1;
	cnt[2]=1;
	for(i=3;i<maxn;i++)
	{
		if(flag[i]==0)
		{
			cnt[i]=cnt[i-1]+1;
			if(i%4==1) flag[i]=flag[i-1]+1;
			else flag[i]=flag[i-1];
		}
		else
		{
			cnt[i]=cnt[i-1];
			flag[i]=flag[i-1];
		}
	}
}
int main()
{
	int x,y,xx;
	init();
	while(scanf("%d%d",&x,&y))
	{
		if(x==-1&&y==-1) break;
		else if(y<2)
		{
			printf("%d %d 0 0\n",x,y);
		}
		else
		{
			xx=x;
			if(xx<=0) xx=1;
			printf("%d %d %d %d\n",x,y,cnt[y]-cnt[xx-1],flag[y]-flag[xx-1]);
		}
	}
	return 0;
}
