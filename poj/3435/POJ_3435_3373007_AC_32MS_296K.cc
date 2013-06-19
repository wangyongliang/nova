#include <stdio.h>
#include <memory.h>
#define SIZE 105

int d[SIZE][SIZE];

bool vis[SIZE];
int main()
{
	int n,i,j,si,sj;
	scanf("%d",&n);
	for(i = 1; i <= n*n; i++)
	{
		for(j = 1; j <= n*n; j++)
			scanf("%d",&d[i][j]);
	}
	bool flg = true;
	for(i = 1; i <= n*n && flg; i++)
	{
		memset(vis,0,sizeof(vis));
		for(j = 1; j <= n*n; j++)
		{
			if(d[i][j] && vis[d[i][j]])
			{
				flg =  false;
				break;
			}
			vis[d[i][j]] = 1;
		}
	}
	for(i = 1; i <= n*n && flg; i++)
	{
		memset(vis,0,sizeof(vis));
		for(j = 1; j <= n*n; j++)
		{
			if(d[j][i] && vis[d[j][i]])
			{
				flg =  false;
				break;
			}
			vis[d[j][i]] = 1;
		}
	}
	for(si = 1; si <= n && flg; si++)
	{
		for(sj = 1; sj <= n && flg; sj++)
		{
			memset(vis,0,sizeof(vis));
			for(i = (si-1)*n+1; i <= si*n && flg; i++)
			{
				for(j = (sj-1)*n+1; j <= sj*n; j++)
				{
					if(d[j][i] && vis[d[j][i]])
					{
						flg =  false;
						break;
					}
					vis[d[j][i]] = 1;
				}
			}
		}
	}
	if(flg)
		printf("CORRECT\n");
	else
		printf("INCORRECT\n");
	return 0;
}