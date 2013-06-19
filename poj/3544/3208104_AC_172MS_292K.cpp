#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
const int maxint=0x7fffffff;
const int maxn=1001;
typedef __int64 int64;
typedef struct Node
{
	int i,j;
	int64 val;
	Node () {}
	Node (int _i, int _j,int64 _val)
	{
		i = _i, j = _j, val=_val;
	}
}Node;
struct cmp
{
	bool operator () (const Node &a, const Node &b)
	{
		return a.val < b.val;
	}
};
int N,t,wt[maxn],d[maxn],p[maxn],match[maxn],vis[maxn];
int64 xx[maxn];
priority_queue<Node,vector<Node>,cmp> q1,q2;
Node a[maxn*maxn];
int num;

int main()
{
	int i,j,k,v;
	Node x;
	scanf("%d%d",&N,&t);
	for (i=0; i<N; i++)
		scanf("%d",&wt[i]);
	for (i=0; i<N; i++)
		scanf("%d",&d[i]);
	for (i=0; i<N; i++)
		scanf("%d",&p[i]),xx[i] = int64(p[i]) - int64(d[i])*t;
	for (k=0; k<N; k++)
	{
		v = -1;
		for (i=0; i<N; i++)
		{
			if (!vis[i] && (v==-1 || wt[i]>wt[v]))
				v = i;
		}
		i = v;
		v = -1;
		for (j=0; j<N; j++)
		{
			if (!match[j] && (v==-1 || xx[j]>xx[v]))
				v = j;
		}
		j = v;
		match[j] = i+1;
		vis[i] = 1;
	}
	for (i=0; i<N; i++)
		printf("%d ",match[i]);
	return 0;
}
