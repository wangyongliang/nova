#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 100010
struct node
{
	int x,id;
};
vector<node> a[maxn];
int dfsn[maxn],low[maxn],p[maxn],flag[maxn],stack[maxn*2],vis[maxn];
int num,top,total;;
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
void dfs(int x,int id)
{
	low[x]=dfsn[x]=num++;
	stack[top++]=x;
	vis[x]=1;
	int i;
	for(i=0;i<a[x].size();i++)
	{
		if(a[x][i].id==id) continue;
		if(vis[a[x][i].x])  low[x]=min(low[x],dfsn[a[x][i].x]);
		else
		{
			p[a[x][i].x]=x;
			dfs(a[x][i].x,a[x][i].id);
			low[x]=min(low[x],low[a[x][i].x]);
		}
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
		total++;
	}
	
}
int find(int x)
{
	if(flag[x]==x) return x;
	else
	{
		int y;
		y=find(flag[x]);
		flag[x]=y;
		return y;
	}
}

int father(int x,int y)
{
	//x=find(x),y=find(y);
	int xx,yy;
	xx=x;
	yy=y;
	int ans=-1;
	/*while(1)
	{
		vis[xx]++;
		vis[yy]++;
		if(vis[xx]>=2||vis[yy]>=2){
		if(vis[xx]>=2) 	ans=xx;
		if(vis[yy]>=2) ans=yy;
		break;
		}
		if(xx!=p[xx])
		{
			p[xx]=find(p[xx]);
			xx=p[xx];
		}
		if(yy!=p[yy])	
		{
			p[yy]=find(p[yy]);
			yy=p[yy];
		}
	}
	*/
	while(xx!=p[xx])
	{
		vis[xx]=1;
		p[xx]=find(p[xx]);
		xx=p[xx];
	}
	vis[xx]=1;
	do
	{
		vis[yy]++;
		if(vis[yy]==2) {
			ans=yy;
			break;
		}
		p[yy]=find(p[yy]);
		yy=p[yy];
	}
	while(yy!=p[yy]);
	if(ans==-1) ans=yy;
	while(x!=xx)
	{
		vis[x]=0;
		x=p[x];
	}
	while(y!=yy)
	{
		vis[y]=0;
		y=p[y];
	}
	vis[x]=0;
	vis[y]=0;
	return ans;
}
int main()
{
	int n,m,i,j;
	int t=1;
	while(scanf("%d%d",&n,&m)&&(n+m))
	{
		for(i=0;i<=n;i++) 
		{
			a[i].clear();
			vis[i]=0;
		}
		num=1;
		while(m--)
		{
			scanf("%d%d",&i,&j);
			node tp;
			tp.id=num++;
			tp.x=j;
			a[i].push_back(tp);
			tp.x=i;
			a[j].push_back(tp);
		}
		p[1]=1;
		top=total=num=0;
		dfs(1,-1);
		int q;
		scanf("%d",&q);
		printf("Case %d:\n",t++);
		for(i=0;i<=n;i++) vis[i]=0;
		while(q--)
		{
			scanf("%d%d",&i,&j);
			i=find(i);
			j=find(j);
			if(i!=j){
			int fa=father(i,j);
			while(i!=fa)
			{
				flag[i]=fa;
				if(flag[i]!=i) total--;
				i=p[i];
			}
			while(j!=fa)
			{
				flag[j]=fa;
				if(flag[j]!=j) total--;
				j=p[j];
			}}
			printf("%d\n",total-1);
			
		}
		printf("\n");
	}
	return 0;

}