#include<stdio.h>
#include<vector>
#include<algorithm>
typedef __int64 int64;
using namespace std;
struct node
{
	int i;
};
struct Mode
{
	int i,j;
	int64 sum;
	int k;
}ans[10009];
vector <node> a[10009];
int b[10009],n;
bool flag[10009];
void dfs(int k)
{
	vector <node> ::iterator it;
	for(it=a[k].begin();it!=a[k].end();it++)
	{
		if(flag[it->i])
		{
			flag[it->i]=0;
			dfs(it->i);
			b[k]+=b[it->i];
		}
	}
}
bool cmp(const Mode &x,const Mode &y)
{
	return x.sum<y.sum;
}
int main()
{
	int sh,sc,i,j,k,l,min;
	node temp;
	while(scanf("%d%d%d%d",&n,&k,&sh,&sc)!=EOF)
	{
		for(i=1;i<=n;i++) a[i].clear();
		sc=sh-sc;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&ans[i].i,&ans[i].j,&ans[i].sum);
			ans[i].k=i+1;
			temp.i=ans[i].j;
			a[ans[i].i].push_back(temp);
			temp.i=ans[i].i;
			a[ans[i].j].push_back(temp);
		}
		for(i=1;i<=n;i++) flag[i]=b[i]=1;
		flag[1]=0;
		dfs(1);
		for(i=0;i<n-1;i++)
		{
			if(b[ans[i].i]<b[ans[i].j]) min=b[ans[i].i];
			else min=b[ans[i].j];
			ans[i].sum=(n-min)*min*ans[i].sum*sc;
		}
		sort(ans,ans+n-1,cmp);
		for(i=0;i<k;i++) printf("%d ",ans[i].k);
		printf("\n");
	}
	return 0;
}