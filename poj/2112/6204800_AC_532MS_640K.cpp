#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 250

int g[MAXN][MAXN], mat[MAXN][MAXN];
int K, C, M;
int que[MAXN], pre[MAXN], head, tail;
void input ()
{
	int i, j;
	
	scanf ("%d%d%d", &K, &C, &M);
	for (i = 1; i <= K + C; i++)
		for (j = 1; j <= K + C; j++)
			scanf ("%d", &g[i][j]);
}
void floy ()
{
	int i, j, k;
	for (k = 1; k <= K + C; k++)
		for (i = 1; i <= K + C; i++)
			for (j = 1; j <= K + C; j++)
				if (g[i][k] && g[k][j] && (!g[i][j] | g[i][j] > g[i][k] + g[k][j]))
					g[i][j] = g[i][k] + g[k][j];
				
}
void create (int mid)
{
	int i, j;
	
	memset (mat, 0, sizeof (mat));
	for (i = 1; i <= K; i++)
		for (j = K + 1; j <= K + C; j++)
			if (g[i][j] && g[i][j] <= mid)
			{
				mat[i][j] = 1;}
			for (i = 1; i <= K; i++)
				mat[0][i] = M;
			for (i = K + 1; i <= K + C; i++)
				mat[i][K + C + 1] = 1; 
}
int find ()
{
	int i, u, v;
	
	memset (pre, -1, sizeof (pre));
	que[0] = 0;
	pre[0] = 0;
	head = tail = 0;
	while (head <= tail)
	{
		u = que[head]; 
		for (i = 1; i <= K + C + 1; i++)
			if (mat[u][i] > 0 && pre[i] == -1)
			{
				pre[i] = u; 
				que[++tail] = i;
				if (i == K + C + 1)
					return 1;
			}
			head++;
	}
	return 0;
}
int max_flow ()
{
	int flow = 0, mini, t;
	
	while (find ())
	{
		mini = 99999999;
		t = K + C + 1; 
		while (t != 0)
		{
			if (mat[pre[t]][t] < mini)
				mini = mat[pre[t]][t];
			t = pre[t];
		}
		t = K + C + 1;
		while (t != 0)
		{
			mat[pre[t]][t] -= mini;
			mat[t][pre[t]] += mini;
			t = pre[t];
		}
		flow += mini;
	}
	return flow;
}
void solve ()
{
	int low, hight, mid;
	
	low = 0, hight = 1000005;
	while (low < hight)
	{
		mid = (low + hight) / 2;
		create (mid);
		if (max_flow () == C)
			hight = mid ;
		else low = mid + 1;
	}
	printf ("%d\n", low);
}
int main ()
{
	input ();
	floy ();
	solve ();
	return 0;
}