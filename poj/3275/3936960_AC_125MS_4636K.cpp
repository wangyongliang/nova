#include<stdio.h>
#include<vector>
using namespace std;
vector<int> a[1100];
int b[1100][1100];
bool flag[1100];
void dfs(int s,int i)
{
	flag[i]=0;
	int k;
	b[s][i]=1;
	for(k=0;k<a[i].size();k++)
	{
		if(flag[a[i][k]])
		{
			dfs(s,a[i][k]);
		}
	}
}
int main()
{
	int n,m;
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++) 
		{
			for(j=0;j<n;j++) b[i][j]=0;
			a[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			i--;
			j--;
			a[i].push_back(j);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) flag[j]=1;
			dfs(i,i);
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(b[i][j]==0&&b[j][i]==0) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}