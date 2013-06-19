#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 0x7FFFFFF;
typedef struct RECORD
{
	int s,e,r;
}RECORD;
int m,n,st,ed;
char map[110][37];
int dp[111][37],pre[111][37];
int num,d1[111],d2[111];
RECORD rec[111],tmp[111];
bool cmp(const RECORD &a, const RECORD &b)
{
	if (a.s != b.s) return a.s < b.s;
	return a.e < b.e;
}

int better()
{
	for (int i=st; i<ed; i++)
	{
		if (d1[i] == d2[i]) continue;
		else if (d1[i]>d2[i])
			return 1;
		else
			return 0;
	}
	return 0;
}

int ok(int d, int a, int b)
{
	if (d==st)
	{
		if (a == b) return 0;
		else if (a<b) return -1;
		return 1;
	}
	int c = ok(d-1,pre[d][a],pre[d][b]);
	if (c!=0) return c;
	if (a == b) return 0;
	if (a<b) return -1;
	return 1;
}
void solve()
{
	int i,j,t,k;
	RECORD T;
	memset(pre,-1,sizeof(pre));
	memset(dp,-1,sizeof(dp));
	for (i=0; i<n; i++)
	{
		if (map[st][i] == 'O')
			dp[st][i] = 0;
	}
	for (k=st+1; k<ed; k++)
	{
		for (i=0; i<n; i++)
		{
			if (map[k][i] == 'X') continue;
			for (j=0; j<n; j++)
			{
				if (dp[k-1][j]>=0)
				{
					if (i==j)
					{
						t = dp[k-1][j];
					}
					else
					{
						t = dp[k-1][j] + 1;
					}
					if (dp[k][i]<0 || dp[k][i]>t)
					{
						dp[k][i] = t;
						pre[k][i] = j;
					}
					
					else if(dp[k][i] == t)
					{
						int ret = ok(k-1,j,pre[k][i]);
						if (ret<0)
						{
							pre[k][i] = j;
						}
					}
					
					
				}
			}
		}
	}
	t = maxn,k=-1;
	for (i=0; i<n; i++)
	{
		if (dp[ed-1][i]>=0 && t > dp[ed-1][i])
		{
			t = dp[ed-1][i];
			k = i;
		}
	}
	if (k<0)
	{
		puts("Not available\n");
		return;
	}
	num = 0;
	k = 0;
	int f = 1;
	for (i=0; i<n; i++)
	{
		if (dp[ed-1][i] == t)
		{
			num = 0;
			T.r = i;
			T.e = ed;
			T.s = ed-1;
			for (j=ed-1; j>=st; j--)
			{
				d2[j] = T.r;
				if (pre[j][T.r] == T.r)
				{
					T.s--;
				}
				else
				{
					tmp[num++] = T;
					T.r = pre[j][T.r];
					T.e = j;
					T.s = j-1;
				}
			}
			sort(tmp,tmp+num,cmp);
			if (f ||better())
			{
				memcpy(rec,tmp,sizeof(tmp));
				memcpy(d1,d2,sizeof(d2));
				f = 0;
			}
		}
	}
	for (i=0; i<t+1; i++)
		printf("%c: %d-%d\n",char(rec[i].r+'A'),rec[i].s+1,rec[i].e+1);
	printf("\n");
}
int main()
{
	int i,cas=0;
	while (scanf("%d%d",&m,&n) && n+m)
	{
		cas++;
		for (i=0; i<m; i++)
			scanf("%s",map[i]);
		scanf("%d%d",&st,&ed);
		st--;
		ed--;
		printf("Case %d:\n\n",cas);
		solve();
	}
	return 0;
}
