#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 5010
int cnt1[maxn],flag1[maxn],cnt2[maxn],flag2[maxn];
vector<int> a[maxn],b[maxn];
int main()
{
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++) 
		{
			flag2[i]=flag1[i]=0;
			cnt2[i]=cnt1[i]=0;
			a[i].clear();
			b[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			b[j].push_back(i);
			flag1[j]++;
			flag2[i]++;
		}
		for(i=1;i<=n;i++)
		{
			if(flag1[i]==0) cnt1[i]=1;
		}
		while(1)
		{
			for(i=1;i<=n;i++)
			{
				if(flag1[i]==0) break;
			}
			if(i==n+1) break;
			for(j=0;j<a[i].size();j++)
			{
				cnt1[a[i][j]]+=cnt1[i];
				flag1[a[i][j]]--;
			}
			flag1[i]=-1;
		}
		for(i=1;i<=n;i++)
		{
			if(flag2[i]==0) cnt2[i]=1;
		}
		while(1)
		{
			for(i=1;i<=n;i++)
			{
				if(flag2[i]==0) break;
			}
			if(i==n+1) break;
			for(j=0;j<b[i].size();j++)
			{
				cnt2[b[i][j]]+=cnt2[i];
				flag2[b[i][j]]--;
			}
			flag2[i]=-1;
		}
		j=0;
		for(i=1;i<n;i++)
		{
			for(int k=0;k<a[i].size();k++)
			{
				if(j<cnt1[i]*cnt2[a[i][k]]) j=cnt1[i]*cnt2[a[i][k]];
			}
		}
		printf("%d\n",j);
	}
	return 0;
}