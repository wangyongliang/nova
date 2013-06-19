#include<stdio.h>
#include<vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> a[2200],b[2100];
int n;
int flag[2200],flg[2200];
int st,q[2200];
void dfs1(int x)
{
	int i;
	flg[x]=1;
	for(i=0;i<a[x].size();i++)
	{
		if(flg[a[x][i]]==0)
		{
			dfs1(a[x][i]);
		}
	}
	q[st++]=x;
}
int p[2200],pp;
void dfs2(int x)
{
	flg[x]=2;
	int i;
	for(i=0;i<b[x].size();i++)
	{
		if(flg[b[x][i]]==1)
		{
			dfs2(b[x][i]);
		}
	}
	p[pp++]=x;
}
int find(int x)
{
	if(x==flag[x]) return x;
	else
	{
		int y=find(flag[x]);
		flag[x]=y;
		return y;
	}
}
void scc()
{
	int i;
	int x,y;
	for(i=0;i<n*2;i++)
	{
		if(flg[i]==0)
		{
			st=0;
			dfs1(i);
			for(st--;st>=0;st--)
			{
				if(flg[q[st]]==1)
				{
					pp=0;
					dfs2(q[st]);
					x=find(p[pp-1]);
					for(pp-=2;pp>=0;pp--)
					{
						y=find(p[pp]);
						flag[y]=x;
					}
				}
			}
		}
	}
	for(i=0;i<2*n;i++) x=find(i);
}

struct node
{
	int x,y;
}point[1000];
node s1,s2;
int A[1010][2];
int B[1010][2];

int cnt_a,cnt_b;
int ABS(int x)
{
	if(x>0) return x;
	else return -x;
}
int dis (node tp1,node tp2)
{
	return ABS(tp1.x-tp2.x)+ABS(tp1.y-tp2.y);
}
void build(int mid)
{
	int i,j;
	for(i=0;i<n*2;i++) 
	{
		a[i].clear();
		b[i].clear();
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			int x=i;
			int y=j;
			if(dis(point[x],s1)+dis( point[y],s1)>mid)
			{
				a[x].push_back(y+n);
				a[y].push_back(x+n);
			}
			if(dis(point[x],s2)+dis(point[y],s2)>mid)
			{
				a[x+n].push_back(y);
				a[y+n].push_back(x);
			}
			if(dis(point[x],s1)+dis(point[y],s2)+dis(s1,s2)>mid)
			{
				a[x].push_back(y);
				a[y+n].push_back(x+n);
			}
			if(dis(point[x],s2)+dis(point[y],s1)+dis(s1,s2)>mid)
			{
				a[y].push_back(x);
				a[x+n].push_back(y+n);
			}
		}
	}
	for(i=0;i<cnt_a;i++)
	{
		int x=A[i][0];
		int y=A[i][1];
		
//		if(dis(point[x],s1)+dis( point[y],s1)>mid)
		{
			a[x].push_back(y+n);
			a[y].push_back(x+n);
		}
//		if(dis(point[x],s2)+dis(point[y],s2)>mid)
		{
			a[x+n].push_back(y);
			a[y+n].push_back(x);
		}
	}
	
	for(i=0;i<cnt_b;i++)
	{
		int x=B[i][0];
		int y=B[i][1];
	//	if(dis(point[x],s1)+dis(point[y],s2)+dis(s1,s2)>mid)
		{
			a[x].push_back(y);
			a[y+n].push_back(x+n);
		}
	//	if(dis(point[x],s2)+dis(point[y],s1)+dis(s1,s2)>mid)
		{
			a[y].push_back(x);
			a[x+n].push_back(y+n);
		}
	}
	for(i=0;i<n*2;i++)
	{
		flag[i]=i;
		flg[i]=0;
		for(j=0;j<a[i].size();j++)
		{
			b[a[i][j]].push_back(i);
		}
	}
	/*
	for(i=0;i<2*n;i++)
	{
		cout<<i<<":";
		for(j=0;j<a[i].size();j++) 
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
}

int check(int mid)
{
	int i;
	build(mid);
	scc();
	for(i=0;i<n;i++)
	{
		if(flag[i]==flag[n+i]) return 0;
	}
	return 1;
}

int main()
{
	int i,j;
	int minlen,maxlen,midlen;

	while(scanf("%d%d%d",&n,&cnt_a,&cnt_b)!=EOF)
	{
		scanf("%d%d%d%d",&s1.x,&s1.y,&s2.x,&s2.y);

		for(i=0;i<n;i++) scanf("%d%d",&point[i].x,&point[i].y);
		for(i=0;i<cnt_a;i++) 
		{
			scanf("%d%d",&A[i][0],&A[i][1]);
			A[i][0]--;
			A[i][1]--;
		}
		for(i=0;i<cnt_b;i++)
		{
			scanf("%d%d",&B[i][0],&B[i][1]);
			B[i][0]--;
			B[i][1]--;
		}
		
		minlen=0;
		maxlen=100000000;
	//	cout<<check(maxlen)<<endl;
		while(minlen<maxlen)
		{
			midlen=(minlen+maxlen)/2;
			if(check(midlen)) maxlen=midlen;
			else minlen=midlen+1;
		}
		if(check(minlen)) printf("%d\n",minlen);
		else printf("-1\n");
	}
	return 0;
}

