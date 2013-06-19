
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//pku 3293

#include<stdio.h>
#include<vector>
#define maxn 160
using namespace std;
vector <int > a[maxn];
int b[maxn][maxn];
int cnt[maxn];
bool flag[maxn];
int n;
void dfs(int x)
{
	vector<int> ::iterator it;
	int flg[maxn]={0};
	int temp[maxn];
	int i,j,k,ct=0;
	for(it=a[x].begin();it!=a[x].end();it++)
	{
		if(flag[*it])
		{
			ct++;
			flg[*it]=1;
			flag[*it]=0;
			dfs(*it);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(flg[i])
		{
			cnt[x]+=cnt[i]+1;
			for(k=1;k<=n;k++)
			{
				temp[k]=b[x][k];
				for(j=1;j<k;j++)
				{
					if(temp[k]>b[i][j]+b[x][k-j]) temp[k]=b[i][j]+b[x][k-j];
				}
			}
			for(k=1;k<=n;k++) b[x][k]=temp[k];
			for(k=1;k<=n;k++)
			{
				if(b[x][k]>b[i][k]) b[x][k]=b[i][k];
			}
			b[x][cnt[i]+1]=1;
		}
	}
	b[x][cnt[x]+1]=1;
}
int  main()
{
	int i,j,p,k;
	int ans;
	int c[maxn][2];
	while(scanf("%d %d",&n,&p)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			a[i].clear();
			c[i][0]=c[i][1]=0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d %d",&k,&j);
			c[k][0]++;
			c[j][1]++;
			a[k].push_back(j);
			a[j].push_back(k);
		}
		ans=maxn;
		for(i=1;i<=1;i++)
		{
			if(c[i][1]==0){
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++) b[j][k]=maxn;
				flag[j]=1;
				cnt[j]=0;
			}
			flag[i]=0;
			dfs(i);
			if(ans>b[i][n-p]) ans=b[i][n-p];
			}
		}
		for(i=2;i<=n;i++)
		{
			if(cnt[i]+1-p>=0&&ans>b[i][cnt[i]+1-p]+1) ans=b[i][cnt[i]+1-p]+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}