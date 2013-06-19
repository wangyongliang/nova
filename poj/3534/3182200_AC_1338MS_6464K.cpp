#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 50010;

typedef struct Point 
{
	double x,y;
	Point () {}
	Point (double _x, double _y) {x=_x,y=_y;}
	double dist(Point &p)
	{
		return sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
	}
}Point;

typedef struct Node
{
	int v,t;
	Node () {}
	Node (int _v, int _t) {v=_v,t=_t;}
}Node;

struct cmp
{
	bool operator () (const Node &a, const Node &b)
	{
		return a.t > b.t;
	}
};

vector<Node> V[maxn];
Point pts[maxn];
int n,m,v;
bool vis[maxn];
int cost[maxn];

priority_queue<Node,vector<Node>,cmp> q;


int work()
{
	int i,j;
	Node t;
	t.v = 0;
	t.t = 0;
	q.push(t);
	memset(cost,-1,sizeof(cost));
	cost[0] = 0;
	while (!q.empty())
	{
		while (!q.empty() && vis[q.top().v]) q.pop();
		if (q.empty()) break;
		t = q.top();
		q.pop();
		vis[t.v] = true;
		if (t.v==n-1)
			return t.t;
		for (i=0; i<V[t.v].size(); i++)
		{
			j = V[t.v][i].v;
			if (vis[j] || pts[j].dist(pts[0])<v*(t.t+V[t.v][i].t)) continue;
			if ((pts[j].dist(pts[0]) == v*(t.t+V[t.v][i].t) && j==n-1))
			{
				q.push(Node(j,t.t+V[t.v][i].t));
				continue;
			}
			else if (pts[j].dist(pts[0]) == v*(t.t+V[t.v][i].t) && j!=n-1)
			continue;
			
			if (pts[j].dist(pts[0]) > pts[t.v].dist(pts[0]) || j == n-1)
			{
				q.push(Node(j,t.t+V[t.v][i].t));
			}
		}
	}
	return -1;
}

int main()
{
	int i,j,k;
	scanf("%d%d%d",&n,&m,&v);
	for (i=1; i<=n; i++)
		scanf("%lf%lf",&pts[i].x,&pts[i].y);
	while (m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		V[i].push_back(Node(j,k));
		V[j].push_back(Node(i,k));
	}
	scanf("%lf%lf%lf%lf",&pts[0].x,&pts[0].y,&pts[n+1].x,&pts[n+1].y);
	n+=2;
	k = work();
	if (k<0)
	{
		puts("Impossible");
	}
	else
		printf("%d\n",k);
		//while (1);
	return 0;
}

