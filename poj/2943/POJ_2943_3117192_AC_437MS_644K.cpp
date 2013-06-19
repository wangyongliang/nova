#include<stdio.h>
#include<algorithm>
using namespace std;
int a[310][310],cnt[310],b[310][310],c[310],n;
bool cmp(const int &x,const int &y)
{
	return cnt[x]<cnt[y];
}
int f(int x,int y)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(a[x][i]&&!a[y][i]) return 0;
	}
	return 1;
}
void g(int x,int y)
{
	int  i;
	for(i=0;i<=n;i++)
	{
		if(a[x][i]) 
		{
			if(b[y][i]) cnt[y]--,b[y][i]=0;
		}
	}
}
int main()
{
	int m,i,j,k,ans;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		ans=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<=n;j++) b[i][j]=a[i][j]=0;
		}
		for(i=0;i<m;i++)
		{
			c[i]=i;
			scanf("%d",&cnt[i]);
			for(j=0;j<cnt[i];j++)
			{
				scanf("%d",&k);
				a[i][k]=b[i][k]=1;
			}
		}
		for(i=0;i<m;i++)
		{
			cnt[i]=0;
			for(j=0;j<=n;j++) cnt[i]+=a[i][j];
		}
		sort(c,c+m,cmp);
		for(i=0;i<m;i++)
		{
			if(cnt[c[i]])
			{
				for(j=i+1;j<m;j++)
				{
					if(f(c[i],c[j])) g(c[i],c[j]);
				}
			}
			else ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

