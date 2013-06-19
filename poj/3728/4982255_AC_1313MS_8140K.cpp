#include<iostream>
#include<vector>
using namespace std;
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define maxn 51000
vector<int> a[maxn];
int pathnum,p[maxn],id[maxn],pathcnt[maxn],pathend[maxn];
int sum[maxn];
int price[maxn],father[maxn];
int deep[maxn],n; //记录深度

void dfs(int x,int fa,int dep)
{
	father[x]=fa;
	deep[x]=dep;
	int maxid=-1;
	for(int i=0;i<a[x].size();i++)
	{
		if(a[x][i]!=fa)
		{ 
			dfs(a[x][i],x,dep+1);
			if(maxid==-1) maxid=a[x][i];
			sum[x]+=sum[a[x][i]];
			if(sum[a[x][i]]>sum[maxid]) maxid=a[x][i];
		}
	}
	if(maxid!=-1)
	{
		p[x]=p[maxid];
		id[x]=pathcnt[p[x]];
		pathcnt[p[x]]++;
		pathend[p[x]]=x;
	}
	else 
	{
		p[x]=pathnum;
		id[x]=0;
		pathcnt[pathnum]=1;
		pathend[pathnum++]=x;
	}

}

int b[maxn];
struct node
{
	int min,max,ans,minx,maxx;
	int ans1;
}tree[maxn*3];

void build(int x,int minx,int maxx)
{
	int midx=(minx+maxx)/2;	
	tree[x].minx=minx;
	tree[x].maxx=maxx;
	if(minx==maxx)
	{
		tree[x].ans1=tree[x].ans=0;
		tree[x].min=tree[x].max=price[b[minx]];
	}
	else
	{
		build(x*2,minx,midx);
		build(x*2+1,midx+1,maxx);
		tree[x].ans=MAX(tree[x*2].ans,tree[x*2+1].ans);
		tree[x].ans=MAX(tree[x].ans,tree[x*2+1].max-tree[x*2].min);
		tree[x].ans1=MIN(tree[x*2].ans1,tree[x*2+1].ans1);
		tree[x].ans1=MIN(tree[x].ans1,tree[x*2+1].min-tree[x*2].max);
		tree[x].min=MIN(tree[x*2].min,tree[x*2+1].min);
		tree[x].max=MAX(tree[x*2].max,tree[x*2+1].max);
	}
}

int dv[200][2],divcnt;
int dv1[200][2],divcnt1;

void LCA(int u,int v)
{
	int tp1[300][3],tp2[300][3],tq1,tq2,i;
	tq1=tq2=0;
	int uu,vv;
	uu=u;
	vv=v;
	while(uu)
	{
		tp1[tq1][0]=p[uu];//保存路径编号
		tp1[tq1][1]=uu; //保存进入该路径的节点
		tq1++;
		uu=pathend[p[uu]];
		uu=father[uu];
	}
	while(1)
	{
		for(i=0;i<tq1;i++)
		{
			if(tp1[i][0]==p[vv]) break;
		}
		if(i==tq1)
		{
			tp2[tq2][0]=p[vv];
			tp2[tq2][1]=vv;
			tq2++;
			vv=pathend[p[vv]];
			vv=father[vv];
		}
		else break;
	}
	int lca;
	if(deep[tp1[i][1]]<deep[vv]) lca=tp1[i][1];
	else lca=vv;
	while(p[u]!=p[lca])
	{
		dv[divcnt][0]=sum[p[u]]+id[u];
		u=pathend[p[u]];
		dv[divcnt][1]=sum[p[u]]+id[u];
		u=father[u];
		divcnt++;
	}
	if(u!=lca) 
	{
		dv[divcnt][0]=sum[p[u]]+id[u];
		dv[divcnt][1]=sum[p[u]]+id[lca];
		divcnt++;
	}
	tq1=0;
	while(p[v]!=p[lca])
	
	{
		dv1[divcnt1][0]=sum[p[v]]+id[v];
		v=pathend[p[v]];
		dv1[divcnt1][1]=sum[p[v]]+id[v];
		v=father[v];
		divcnt1++;
	}
	if(v!=lca)
	{
		dv1[divcnt1][0]=sum[p[v]]+id[v];
		dv1[divcnt1][1]=sum[p[v]]+id[lca];
		divcnt1++;
	}
	if(v==lca&&u==lca)
	{
		dv[divcnt][0]=sum[p[lca]]+id[lca];
		dv[divcnt][1]=sum[p[lca]]+id[lca];
		divcnt++;
	}

}
int maxw;
void query(int minx,int maxx,int &ans,int &min,int &max,int x,int &ans1)
{
	if(minx<=tree[x].minx&&maxx>=tree[x].maxx)
	{
		ans=tree[x].ans;
		ans1=tree[x].ans1;
		min=tree[x].min;
		max=tree[x].max;
	}
	else
	{
		int midx=(tree[x].minx+tree[x].maxx)/2;
		int tpans=0,tpmin=0,tpmax=0,tpans1=0;
		int tpmin1=0,tpmax1=0,tpans11=0;
		ans=0;
		min=maxw;
		max=-1;
		int flg=0;
		if(minx<=midx)
		{
			query(minx,maxx,tpans,tpmin,tpmax,x*2,tpans1);
			ans=MAX(ans,tpans);
			ans1=MIN(ans1,tpans1);
			min=MIN(min,tpmin);
			max=MAX(max,tpmax);
			tpans1=tpans,tpmin1=tpmin,tpmax1=tpmax;
			tpans11=tpans1;
			flg=1;
		}
		if(maxx>midx)
		{
			query(minx,maxx,tpans,tpmin,tpmax,x*2+1,tpans1);
			ans=MAX(ans,tpans);
			ans1=MIN(ans1,tpans1);
			min=MIN(min,tpmin);
			max=MAX(max,tpmax);
			if(flg) 
			{
				ans=MAX(ans,tpmax-tpmin1);
				ans1=MIN(ans1,tpmin-tpmax1);
			}			
		}
	}
}
int Q(int u,int v)
{
	divcnt1=divcnt=0;
	LCA(u,v);
	int ans=0;
	int min=maxw+1;
	int max=-1;
	int tpans,tpmin,tpmax,tpans1;
	for(int i=0;i<divcnt;i++)
	{
		query(dv[i][0],dv[i][1],tpans,tpmin,tpmax,1,tpans1);
		ans=MAX(ans,tpans);
		ans=MAX(ans,tpmax-min);
		min=MIN(min,tpmin);
	}
	for(int i=divcnt1-1;i>=0;i--)
	{
		tpans=tpmin=tpmax=tpans1=0;
		query(dv1[i][0],dv1[i][1],tpans,tpmin,tpmax,1,tpans1);
		ans=MAX(ans,-tpans1);
		ans=MAX(ans,tpmax-min);
		min=MIN(min,tpmin);
	}
	return ans;
}
void init()
{
	int i,j;
	pathnum=0;
	dfs(1,0,0);
	for(i=0;i<pathnum;i++)
	{
		if(i==0) sum[i]=0;
		else sum[i]=sum[i-1]+pathcnt[i-1];
	}
	for(i=1;i<=n;i++)
	{
		if(sum[p[i]]+id[i]>n) while(1);
		b[sum[p[i]]+id[i]]=i;
	}
	build(1,0,n-1);
}
int main()
{
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		maxw=-1;
		for(i=1;i<=n;i++) 
		{
			scanf("%d",&price[i]);
			maxw=MAX(maxw,price[i]);
			if(price[i]<0) while(1);
			a[i].clear();
		}
		pathnum=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			a[j].push_back(k);
			a[k].push_back(j);
		}
		init();
		int q;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&i,&j);
			printf("%d\n",Q(i,j));
		}
		
	}
	return 0;
}
