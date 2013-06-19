#include<stdio.h>
#include<vector>
#define maxn 1009
using namespace std;
struct node
{
	int i;
};
	int flg[maxn];
	bool flag[maxn],b[maxn];
vector <node> a[maxn];
void dfs(int x)
{
	int i;
	flag[x]=1;
	flg[x]++;
	vector <node> ::iterator it;
	for(it=a[x].begin();it!=a[x].end();it++)
	{
		if(!flag[it->i])
		{
			dfs(it->i);
		}
	}
}
int main()
{
	int k,n,m,i,j;

	node q;
	while(scanf("%d%d%d",&k,&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++) a[i].clear(),flg[i]=0;
		for(i=0;i<k;i++) 
		{
			scanf("%d",&j);
			b[j]=1;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&j,&q.i);
			a[j].push_back(q);
		}
		for(i=1,k=0;i<=n;i++)
		{
			if(b[i])
			{
				for(j=1;j<=n;j++) flag[j]=0;
				dfs(i);
				k++;
			}
		}
		for(i=1,j=0;i<=n;i++)
		{
			if(flg[i]==k) j++;
		}
		printf("%d\n",j);
	}
	return 0;
}