#include<stdio.h>
#include<algorithm>

using namespace std;
#define maxn 210
int a[maxn][2],d[maxn],c[maxn];
int cnt[maxn][maxn];
int q[maxn];
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int main()
{
	int n,m;
	int t,i,j,k;
	scanf("%d",&t);
	int ct;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<maxn;i++)
			for(j=0;j<maxn;j++) cnt[i][j]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			c[i]=a[i][0];
			d[i]=a[i][1];
		}
		sort(c,c+n);
		sort(d,d+n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n&&c[j]!=a[i][0];j++);
			for(k=0;k<n&&d[k]!=a[i][1];k++);
			cnt[j][k]++;
		}
		for(i=1;i<n;i++)
			for(j=0;j<n;j++) cnt[j][i]+=cnt[j][i-1];
		int ans=1000000000;
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				int st=0,en=0;
				ct=0;
				for(en=0;en<n;en++)
				{
					if(i)	ct+=cnt[en][j]-cnt[en][i-1];
					else ct+=cnt[en][j];
					if(ct>=m)
					{
												while(ct>=m)
						{
							if(i)	ct-=cnt[st][j]-cnt[st][i-1];
							else ct-=cnt[st][j];
							st++;
						}
						ans=min(ans,(c[en]-c[st-1]+2)*(d[j]-d[i]+2));
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}