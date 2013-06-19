#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
bool flag[210][210];
vector<int> a[210];
int ans[210],b[210],cnt[210],n;
int ck()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		if(flag[i][i]) return 0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(cnt[j]==0) break;
		}
		if(j==n) return 0;
		for(int k=0;k<a[j].size();k++)
		{
			cnt[a[j][k]]--;
		}
		cnt[j]=-1;
	}
	return 1;
}
priority_queue<int> heap;
int num;
void dfs(int x)
{
	int i;
	flag[0][x]=0;
	if(ans[x]==-1) num++;
	for(i=0;i<a[x].size();i++)
	{
		if(flag[0][a[x][i]])
		{
			dfs(a[x][i]);
		}
	}
}
int main()
{
	int t,m;
	int i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				flag[i][j]=0;
				
			}
			a[i].clear();
			ans[i]=-1;
			cnt[i]=b[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&j,&i);
			flag[--i][--j]=1;
		//	cnt[j]++;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(flag[i][j]) 
				{
					a[i].push_back(j);
					cnt[j]++;
				}
			}
		}
		if(ck())
		{
			for(i=0;i<n;i++) cnt[i]=0;
					for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(flag[i][j]) 
				{
					a[i].push_back(j);
					cnt[j]++;
				}
			}
		}
			while(heap.size()) heap.pop();
			for(i=0;i<n;i++)
			{
				if(cnt[i]==0)
					heap.push(i);
			}
			for(i=n-1;i>=0;i--)
			{
				int k=heap.top();
				heap.pop();
				ans[k]=i;
				for(j=0;j<n;j++)
				{
					if(flag[k][j])
					{
						cnt[j]--;
						if(cnt[j]==0) heap.push(j);
					}
				}
			}
			for(i=0;i<n;i++) printf("%d ",ans[i]+1);
			printf("\n");

		}
		else printf("-1\n");
	}
	return 0;
}