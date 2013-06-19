#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 5010
struct node
{
	int x,id;
};
vector<node> a[maxn];
int stack[maxn],top;
int flag[maxn],cnt[maxn],p[maxn],dfsn[maxn],low[maxn],vis[maxn],chd[maxn];
int num;
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int dfs(int x,int up)
{
//	p[x]=y;
	vis[x]=1;
	stack[top++]=x;
	low[x]=dfsn[x]=num++;
	int i;
	int ans=0;
	chd[x]=0;
	for(i=0;i<a[x].size();i++)
	{
		if(i==up) continue;
		if(vis[a[x][i].x]==0)
		{
			p[a[x][i].x]=x;
			chd[x]++;
			ans+=dfs(a[x][i].x,a[x][i].id);
			low[x]=min(low[x],low[a[x][i].x]);
		}
		else low[x]=min(low[x],dfsn[a[x][i].x]);
	}
	if(low[x]==dfsn[x])
	{
		while(stack[top-1]!=x)
		{
			flag[stack[top-1]]=x;
			top--;
		}
		flag[x]=x;
		top--;
		if(x==1)
		{
			if(ans==0) return 0;
			else if(chd[1]==1) return ans+1;
		}
		else{
		if(ans==0) ans++;
		}
	}
	return ans;
}
int main()
{
	int n,m,ans;
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<=n;i++)
		{
			a[i].clear();
			flag[i]=chd[i]=cnt[i]=0;
			vis[i]=0;
		}
		num=1;
		while(m--)
		{
			scanf("%d%d",&i,&j);
			node tp;
			tp.id=a[j].size();
			tp.x=j;
			a[i].push_back(tp);
			tp.x=i;
			tp.id=a[i].size()-1;
			a[j].push_back(tp);
		}
	//	printf("%d\n",a[1].size());
		top=0;
		ans=dfs(1,-1);
	//	if(chd[1]==0) ans=0;
	//	else if(chd[1]==1) ans++;
		printf("%d\n",(ans+1)/2);
	}
	return 0;
}