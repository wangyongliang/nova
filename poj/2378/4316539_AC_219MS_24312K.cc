#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 1000000
vector<int> b[maxn],a[maxn];
int cnt[maxn],n;
vector<int> ans;
bool flag[maxn];
void tree(int x)
{
	int i;
	flag[x]=1;
	int ok=1;
	cnt[x]=1;
	for(i=0;i<a[x].size();i++)
	{
		if(flag[a[x][i]]==0)
		{
			tree(a[x][i]);
			cnt[x]+=cnt[a[x][i]];
			if(cnt[a[x][i]]>n/2) ok=0;
		}
	}
	if(n-cnt[x]>n/2) ok=0;
	if(ok) ans.push_back(x);
}

int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++) 
		{
			a[i].clear();
			cnt[i]=0;
			flag[i]=0;
		}
		for(i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		ans.clear();
		tree(1);
//		printf("size = %d\n",ans.size());
		sort(ans.begin(),ans.end());
		for(i=0;i<ans.size();i++)
		{
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}