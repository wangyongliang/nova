#include <iostream>
#include<stdio.h>
#include <memory.h>
using namespace std;
#define MAXN 50000
int parent[MAXN+1];
int find(int x)
{
	if(parent[x]<0) return x;
	parent[x]=find(parent[x]);
	return parent[x];
}
void Union(int x,int y)
{
	int root1=find(x),root2=find(y);
	if(root1==root2) return;
	if(parent[root1]<parent[root2]) { parent[root1]=-1; parent[root2]=root1; }
	else { parent[root2]=-1; parent[root1]=root2; }
}
int main()
{
	int m,n,k,r1,r2,sum,i;
	while(cin>>m>>n)
	{
		if(m==0&&n==0) break;
		sum=0; memset(parent,-1,sizeof(parent));
		while(n--)
		{
			scanf("%d",&k);
			if(k==0) continue;
			scanf("%d",&r1);
			for(i=0;i<k-1;i++){ scanf("%d",&r2); Union(r1,r2); }
		}
		n=find(parent[0]);
		for(i=1;i<m;i++)
		{
			if(find(i)==n) sum++;
		}
		printf("%d\n",sum+1);
	}
	return 0;
}