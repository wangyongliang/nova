//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//http://acm.pku.edu.cn/JudgeOnline/problem?id=2406
#include<stdio.h>
#include<vector >
#include<algorithm>
#define inf  100000000
using namespace std;
struct node
{
	int x,y;
};
vector<node> a[600];
int f,p,c,m,n;
int close[600];
void dij()
{
	int i,j,min;
	for(i=1;i<=n;i++) close[i]=inf;
	close[1]=0;
	vector <node>::iterator it;
	while(1)
	{
		for(i=1;close[i]==-1;i++);
		min=i;
		for(;i<=n;i++)
		{
			if(close[i]!=-1&&close[i]<close[min]) min=i;
		}
		if(close[min]>m||min>n) break;
		for(it=a[min].begin();it!=a[min].end();it++)
		{
			if(close[it->x]!=-1&&close[it->x]>it->y+close[min])
			{
				close[it->x]=close[min]+it->y;
			}
		}
		close[min]=-1;
	}
}
int main()
{
	node temp;
	int i,j;
	int cow[200];
	while(scanf("%d%d%d%d",&n,&p,&c,&m)!=EOF)
	{
		for(i=1;i<=n;i++) a[i].clear();
		while(p--)
		{
			scanf("%d%d%d",&i,&j,&temp.y);
			temp.x=j;
			a[i].push_back(temp);
			temp.x=i;
			a[j].push_back(temp);
		}
		for(i=0;i<c;i++)
		{
			scanf("%d",&cow[i]);
		}
		dij();
		int ans[100]={0};
		for(m=i=0;i<c;i++)
		{
			if(close[cow[i]]==-1)
			{
				ans[m++]=i;
			}
		}
		sort(ans,ans+m);
		printf("%d\n",m);
		for(i=0;i<m;i++)
		{
			printf("%d\n",ans[i]+1);
		}
	}
	return 0;
}