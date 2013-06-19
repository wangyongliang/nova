#include<stdio.h>
#include<vector>
#define max 100100
using namespace std;
int b[max];
__int64 c[max];
__int64 sum;
__int64 min;
bool flag[max]={0};
vector<int> a[max];
__int64 abs(__int64 n)
{
	if(n>0) return n;
	else return -n;
}
void dfs(int i,int j)
{
	vector<int >::iterator it;
	flag[j]=1;
	for(it=a[i].begin();it!=a[i].end();it++)
	{
		if(!flag[*it])
		{
			flag[*it]=1;
			dfs(*it,i);
		}
	}
	for(it=a[i].begin();it!=a[i].end();it++)
	{
		if(flag[*it]&&*it!=j) 
		{
			c[i]+=c[*it];		
			flag[*it]=0;
		}
	}
	c[i]+=b[i];
}
int main()
{
	int n,m,i,j;
	int t=1;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		sum=0;
		flag[0]=0;
		for(i=1;i<=n;i++)
		{
			a[i].clear();
			flag[i]=0;
			c[i]=0;
			scanf("%d",&j);
			b[i]=j;
			sum+=j;
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			if(i==j) continue;
			a[i].push_back(j);
			a[j].push_back(i);
		}
		flag[1]=1;
		dfs(1,0);
		min=sum;
		for(i=1;i<=n;i++)
		{
			min=abs(sum-c[i]-c[i])<min?abs(sum-c[i]-c[i]):min;
		}
		printf("Case %d: %I64d\n",t++,min);
	}
	return 0;
}