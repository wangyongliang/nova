//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
//2763

#include<stdio.h>
#include<vector >
#include<algorithm>
using namespace std;
#define maxn 300000
int A[maxn],B[maxn],b[maxn][2],R[maxn];
__int64 len[maxn];
struct node
{
	int x,y;
};
vector<node> a[maxn];
int n,m,cnt;
void dfs(int deeps,int i,int j,int lens)
{
	A[cnt]=deeps;
	b[i][0]=m++;
	B[cnt]=i;
	R[i]=cnt;
	len[i]=lens;
	cnt++;
	vector<node >::iterator it;
	for(it=a[i].begin();it!=a[i].end();it++)
	{
	
		if(it->x!=j)
		{
			dfs(deeps+1,it->x,i,lens+it->y);
			A[cnt]=deeps;
			B[cnt]=i;
			cnt++;
		}
	}
	b[i][1]=m-1;
}
struct TREE
{
	bool cov;
	int x,y,dis;
}tree[maxn];
void build(int x,int y,int fa)
{
	tree[fa].x=x;
	tree[fa].y=y;
	if(x==y)
	{
		tree[fa].cov =0;
		tree[fa].dis=0;
	}
	else
	{
		build(x,(x+y)/2,fa*2);
		build((x+y)/2+1,y,fa*2+1);
	}
}
void insert(int x,int y,int fa,int dis)
{
	if(x<=tree[fa].x&&y>=tree[fa].y)
	{
		tree[fa].cov=1;
		tree[fa].dis+=dis;
	}
	else
	{
		if(x<=tree[fa*2].y) insert(x,y,fa*2,dis);
		if(y>=tree[fa*2+1].x) insert(x,y,fa*2+1,dis);
	}
}
int get(int i,int fa)
{
	if(tree[fa].x==i&&tree[fa].y==i) return tree[fa].dis;
	else
	{
		if(tree[fa].cov)
		{
			insert(tree[fa].x,tree[fa].y,fa*2,tree[fa].dis);
			insert(tree[fa].x,tree[fa].y,fa*2+1,tree[fa].dis);
			tree[fa].cov=0;
			tree[fa].dis=0;
		}
		if(i<=tree[fa*2].y)		return get(i,fa*2);
		if(i>=tree[fa*2+1].x)
			return get(i,fa*2+1);
	}
}

int M[maxn][30];
void Init_LCA_RMQ()
{
	int i,j;
	for (i=0; i<cnt; i++)
		M[i][0] = i;
	for (j=1; (1<<j)<=cnt; j++)
	{
		for (i=0; i+(1<<j)-1<cnt; i++)
		{
			if (A[M[i][j-1]] > A[M[i+(1<<(j-1))][j-1]])
				M[i][j] = M[i+(1<<(j-1))][j-1];
			else
				M[i][j] = M[i][j-1];
		}
	}
}

int RMQ(int i, int j)
{
	int k = 0;
	while ((1<<(k+1)) < (j-i+1)) k++;
	if (A[M[i][k]] > A[M[j-(1<<k)+1][k]])
		return B[M[j-(1<<k)+1][k]];
	else
		return B[M[i][k]];
}
void init()
{
	int i;
	cnt=0;
	m=1;
	dfs(1,1,0,0);
	build(1,n,1);
	Init_LCA_RMQ();
}
struct Road
{
	int x,y,len;
}road[maxn];
int main()
{
	node temp;
	int i,j,k,q,s;
	int x,y;
	__int64 ans;
	while(scanf("%d%d%d",&n,&q,&s)!=EOF)
	{
		for(i=0;i<=n;i++) a[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d",&road[i].x,&road[i].y,&road[i].len);
			temp.y=road[i].len;
			temp.x=road[i].y;
			a[road[i].x].push_back(temp);
			temp.x=road[i].x;
			a[road[i].y].push_back(temp);
		}
		init();
		while(q--)
		{
			scanf("%d",&i);
			if(i)
			{
				scanf("%d%d",&j,&k);
				x=road[j].x;
				y=road[j].y;
				if(A[R[x]]<A[R[y]]) x=y;
				y=k-road[j].len;
				road[j].len=k;
				insert(b[x][0],b[x][1],1,y);
			}
			else
			{
				scanf("%d",&j);
				if(R[s]<=R[j]) x=RMQ(R[s],R[j]);
				else x=RMQ(R[j],R[s]);
				ans=len[s]+get(b[s][0],1);
				ans+=len[j]+get(b[j][0],1);
				ans-=2*(len[x]+get(b[x][0],1));
				s=j;
				printf("%I64d\n",ans);
			}
		}
	}
	return 0;
}


