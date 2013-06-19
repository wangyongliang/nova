#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 50010

typedef struct Node
{
	int id,val;
}Node;
struct cmp
{
	bool operator () (const Node &a, const Node &b)
	{
		return a.val < b.val;
	}
};
priority_queue<Node,vector<Node>,cmp> q;
int p[SIZE],deg[SIZE];
vector<int> mp[SIZE];
int main()
{
	int i,n,m,a,b;
	vector<int>::iterator it;
	scanf("%d",&n);
	Node tnode;
	for(i = 1; i <= n; i++)
	{
		scanf("%d%d",&a,&b);
		p[i] = a-b;
	}
	scanf("%d",&m);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d",&a,&b);
		deg[b]++;
		mp[a].push_back(b);
	}
	for(i = 1; i <= n; i++)
	{
		if(!deg[i])
		{
			tnode.id = i;
			tnode.val = p[i];
			q.push(tnode);
		}
	}
	while(!q.empty())
	{
		a = q.top().id;
		q.pop();
		printf("%d\n",a);
		for(it = mp[a].begin(); it != mp[a].end(); it++)
		{
			deg[*it]--;
			if(deg[*it] == 0)
			{
				tnode.id = *it;
				tnode.val = p[*it];
				q.push(tnode);
			}
		}
	}
	return 0;
}

