#include<stdio.h>
#define maxn 1000010
int sum[maxn];
int lowerbit(int x)
{
	return x&(-x);
}

int find(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=sum[x];
		x-=x&(-x);
	}
	return ans;
}

void insert(int x)
{
	while(x<maxn)
	{
		 sum[x] ++;
		 x+=x&(-x);
	}
}
int main()
{
	int n,m;
	int i,j;
	int ans=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<maxn;i++) sum[i]=0;
		for(i=0;i<n;i++)		
		{
			scanf("%d",&j);
			ans+=find(m-j);
			insert(j);
		}
		printf("%d\n",ans);
	}
	return 0;
}

