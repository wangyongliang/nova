#include <stdio.h>
#include <memory.h>

#define maxn 201

int n,m;
char in[maxn][maxn];
int mark[maxn][maxn],end[maxn*maxn][2][2],cc;
bool flag[maxn*maxn];

int set[maxn*maxn];

int find(int v)
{
	while (set[v]>0) v = set[v];
	return v;
}

void unit(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa!=pb)
	{
		set[pa] = pb;
	}
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool chk(int i,int j)
{
	return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int x, int y)
{
	int i,px,py,f=0,g=0;
	mark[x][y] = cc;
	for (i=0; i<4; i++)
	{
		px = x+dx[i];
		py = y+dy[i];
		if (!chk(px,py) || in[px][py]=='0') continue;
		if (!mark[px][py])
		{
			dfs(px,py);
		}
	}
	for (i=0; i<4; i++)
	{
		px = x+dx[i];
		py = y+dy[i];
		if (!chk(px,py) || in[px][py] == '0') continue;
		if (mark[px][py])
			f++;
	}
	if (f <=1)
	{
		if (end[cc][0][0]<0)
		{
			end[cc][0][0] = x;
			end[cc][0][1] = y;
		}
		else if (end[cc][1][0]<0)
		{
			end[cc][1][0] = x;
			end[cc][1][1] = y;
		}
		else
		{
			flag[cc] = true;
		}
	}
	else if (f>2)
	{
		flag[cc] = true;
	}
}

bool is(int v)
{
	int ans = 0;
	int i,j,k,x,y,px,py,t;
                    	x = end[v][0][0];
	y = end[v][0][1];

               	for (i=0; i<4; i++)
	{
		px = x+dx[i];
                                                		py = y+dy[i];
		if (!chk(px,py) || mark[px][py]) continue;
	                       	t = 4;
		for (j=0; j<4; j++)
	                          	{
	                              		int pa = px + dx[j];
			int pb = py + dy[j];
			if (!chk(pa,pb) ) continue;
	                            		if (pa == x && pb == y) continue;
			if (mark[pa][pb])
			{
				t--;
	                            		}
		}
		if (t==4) 
			return false;
	}
	if (end[v][1][0]<0)
	return true;
                             	x = end[v][1][0];
	y = end[v][1][1];

	for (i=0; i<4; i++)
	{
                                  		px = x+dx[i];
		py = y+dy[i];
		if (!chk(px,py) || mark[px][py]) continue;
		t = 4;
		for (j=0; j<4; j++)
		{
			int pa = px + dx[j];
			int pb = py + dy[j];
	                                 		if (!chk(pa,pb) ) continue;
			if (pa == x && pb == y) continue;
			if (mark[pa][pb]) 
			{
				t--;
			}
		}
		if (t==4)
			return false;
	}
	return true;
}

void work()
{
	int i,j;
	cc = 1;
                                	memset(mark,0,sizeof(mark));
	memset(end,-1,sizeof(end));
                      	memset(flag,false,sizeof(flag));
	memset(set,-1,sizeof(set));
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (!mark[i][j] && in[i][j] == '1')
			{
				dfs(i,j);
				cc++;
			}
	                                                            	}
	   }
	                          int ans = 0;
	for (i=1; i<cc; i++)
	{
	  	if (flag[i]) continue;
	                                	if (is(i))
		{
			ans++;
		}
	}
	                           printf("%d\n",ans);
}

int main()
{
                         	while (scanf("%d%d",&n,&m) && n+m)
	                          {
		int i;
	                                	for (i=0; i<n; i++)
		{
			scanf("%s",in[i]);
		}
		work();
	}
	return 0;
}
