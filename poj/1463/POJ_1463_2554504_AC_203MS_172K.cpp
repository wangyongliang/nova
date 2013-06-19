#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 1509
int n;
int a[maxn][2];
vector <int> mp[maxn];
bool flag[maxn];
void dfs(int x)
{
	vector <int>::iterator it;
	a[x][0]=a[x][1]=0;
	it=mp[x].begin();
	if(it==mp[x].end())
	{
		a[x][0]=0;
		a[x][1]=1;
	}
	else
	{
		for(;it!=mp[x].end();it++)
		{
			dfs(*it);
		}
		a[x][1]=1;
		for(it=mp[x].begin();it!=mp[x].end();it++)
		{
			a[x][0]+=a[*it][1];
			if(a[*it][1]<a[*it][0]) a[x][1]+=a[*it][1];
			else  a[x][1]+=a[*it][0];
		}
	}
}
int main()
{
	int i,j,k,l;
	vector <int> ::iterator it;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++) 
		{
			mp[i].clear(); 
			flag[i]=1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d:(%d)",&j,&k);
			while(k--)
			{
				scanf("%d",&l);
				flag[l]=0;
				mp[j].push_back(l);
			}
		}
		for(i=0;i<n;i++)
		{
			if(flag[i]) break;
		}
		dfs(i);
		printf("%d\n",a[i][0]<a[i][1]?a[i][0]:a[i][1]);
	}
	return 0;
}