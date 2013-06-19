#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef __int64 int64;

typedef struct Node
{
	int v;
	int64 wt;
	Node () {}
	Node (int _v, int64 _wt) {v = _v, wt = _wt;}
}Node;

typedef struct Edge
{
	int u,v;
	int64 wt;
	Edge () {}
	Edge (int _u, int _v, int64 _wt) { u = _u, v = _v, wt = _wt;}
}Edge;

struct cmp
{
	bool operator () (const Node &a, const Node &b)
	{
		return a.wt > b.wt;
	}
};

vector<Edge> e;
vector<Node> V[10001],VA[10001];
vector<int> ans;
bool vis[10001];
int n,m,K;
int64 dist1[10001], dist2[10001];

void dij1()
{
	int i,j,k;
	Node t;
	priority_queue<Node,vector<Node>,cmp> q;
	memset(dist1,-1,sizeof(dist1));
	q.push(Node(0,0));
	while (!q.empty())
	{
		while (!q.empty() && vis[q.top().v]) q.pop();
		if (q.empty()) break;
		t = q.top();
		q.pop();
		vis[t.v] = true;
		dist1[t.v] = t.wt;
		k = V[t.v].size();
		for (i=0; i<k; i++)
		{
			j = V[t.v][i].v;
			if (!vis[j] && (dist1[j]<0 || dist1[j]>t.wt + V[t.v][i].wt))
			{
				dist1[j] = V[t.v][i].wt + t.wt;
				q.push(Node(j,dist1[j]));
			}
		}
	}
}

void dij2()
{
	int i,j,k;
	Node t;
	priority_queue<Node,vector<Node>,cmp> q;
	memset(dist2,-1,sizeof(dist2));
	memset(vis,false,sizeof(vis));
	q.push(Node(n-1,0));
	while (!q.empty())
	{
		while (!q.empty() && vis[q.top().v]) q.pop();
		if (q.empty()) break;
		t = q.top();
		q.pop();
		vis[t.v] = true;
		dist2[t.v] = t.wt;
		k = VA[t.v].size();
		for (i=0; i<k; i++)
		{
			j = VA[t.v][i].v;
			if (!vis[j] && (dist2[j]<0 || dist2[j]>t.wt + VA[t.v][i].wt))
			{
				dist2[j] = VA[t.v][i].wt + t.wt;
				q.push(Node(j,dist2[j]));
			}
		}
	}
}

int main()
{
	int u,v,wt,i;
	scanf("%d%d%d",&n,&m,&K);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d",&u,&v,&wt);
		u--,v--;
		V[u].push_back(Node(v,wt));
		VA[v].push_back(Node(u,wt));
		e.push_back(Edge(u,v,wt));
	}
	dij1();
	if (dist1[n-1]<0)
	{
		puts("0");
		return 0;
	}
	dij2();
	u = 0;
	for (i=0; i<m; i++)
	{
		if (dist1[e[i].u]>=0 && dist2[e[i].v]>=0 &&dist1[e[i].u] + dist2[e[i].v] + e[i].wt<=dist1[n-1]+K)
		{
			ans.push_back(i+1);
		}
	}
	printf("%d\n",ans.size());
	for (i=0; i<ans.size(); i++)
		printf("%d\n",ans[i]);
	return 0;
}
