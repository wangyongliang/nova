#include <stdio.h>
#include <map>
#include <memory.h>
using namespace std;
#define MAX 0x7FFFFFFF;
#define SIZE 205

struct Node{
	int a,b,c,asum,bsum;
}node[SIZE];
int g[SIZE][SIZE],idx[SIZE];
bool visit[SIZE];
map<int,int> mp;

int n;
void dfs(int k,int root)
{
	visit[k] = true;
	if(idx[k] <= 1 && k != 1)
	{
		node[k].a = node[k].b = node[k].c = 1; 
		node[k].asum = node[k].bsum = 0;
		return;
	}
	node[k].asum = node[k].bsum = 0;
	int t,temp,i;
	for(i = 0; i < idx[k]; i++)
	{
		t = g[k][i];
		if(t != root){
			dfs(t,k);
			node[k].asum += node[t].a;
			node[k].bsum += node[t].b;
		}
	}
	node[k].a = node[k].b = MAX;
	node[k].c = 1;
	for(i = 0; i < idx[k]; i++)
	{
		t = g[k][i];
		if(t != root){
			temp = node[k].bsum - node[t].b + node[t].c;
			if(temp < node[k].a)
				node[k].a = temp;
			temp = node[k].asum - node[t].a + node[t].asum + 1;
			if(temp < node[k].b)
				node[k].b = temp;
			node[k].c += node[t].bsum > node[t].a ? node[t].a : node[t].bsum;
		}
	}
	if(node[k].b > node[k].c)
		node[k].b = node[k].c;
	if(node[k].a > node[k].b)
		node[k].a = node[k].b;
}
int main()
{
	int T,i,j,ina,inb,e;
	scanf("%d",&T);
	while(T--)
	{
		mp.clear();
		memset(idx,0,sizeof(idx));
		memset(node,0,sizeof(node));
		memset(visit,0,sizeof(visit));
		scanf("%d",&e);
		n = 1;
		for(i = 0; i < e; i++)
		{
			scanf("%d%d",&ina,&inb);
			if(mp[ina] == 0)
				mp[ina] = n++;
			if(mp[inb] == 0)
				mp[inb] = n++;
			g[mp[ina]][idx[mp[ina]]++] = mp[inb];
			g[mp[inb]][idx[mp[inb]]++] = mp[ina];
		}
		dfs(1,-1);
		int ans = node[1].a;
		if(ans > node[1].b)
			ans = node[1].b;
		if(ans > node[1].c)
			ans = node[1].c;
		printf("%d\n",ans);
	}
	return 0;
}