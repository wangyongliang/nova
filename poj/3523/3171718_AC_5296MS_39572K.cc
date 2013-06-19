#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define SIZE 16

struct Queue
{
	short x[3];
	int len;
}queue[256*256*256];
int head,tail,w,h;
char map[SIZE*SIZE];
short vis[256][256][256]={0};
short sx[3],sy[3],n,ex[3],ey[3];

int t=0;
int bfs()
{
	//memset(vis,0,sizeof(vis));
	short tx[3],ttx[3],dx[5] = {0,1,-1,w,-w};
	t++;
	vis[sx[0]][sx[1]][sx[2]] = t;
	head = 0;
	tail = 1;
	short i,j,k;
	int tlen;
	for(i = 0; i < n; i++)
		queue[0].x[i] = sx[i];
	queue[0].len = 0;
	while(tail > head)
	{
	//	printf("expand:\n");
		for(i = 0; i < n; i++)
		{
			tx[i] = queue[head].x[i];
		//	printf("%d: (%d,%d)\n",i+1,tx[i]/w,tx[i]%w);
		}
		tlen = queue[head].len;
		head++;
		//printf("---------------\n");
		for(i = 0; i < 5; i++)
		{
			ttx[0] = tx[0] + dx[i];
			if(map[ttx[0]] == '#')
				continue;
			if(n > 1)
			{
				for(j = 0; j < 5; j++)
				{
					ttx[1] = tx[1]+dx[j];
					if(map[ttx[1]] == '#' || (tx[0] == ttx[1] && tx[1] == ttx[0])
						|| ttx[0] == ttx[1])
						continue;
					if(n > 2)
					{
						for(k = 0; k < 5; k++)
						{
							ttx[2] = tx[2] + dx[k];
							if(map[ttx[2]] != '#' && !(ttx[2] == ttx[1] || ttx[2] == ttx[0]) 
								&& !(tx[2] == ttx[1] && tx[1] == ttx[2])
								&& !(tx[2] == ttx[0] && tx[0] == ttx[2])
								&& vis[ttx[0]][ttx[1]][ttx[2]]!=t)
							{
								vis[ttx[0]][ttx[1]][ttx[2]] = t;
								queue[tail].x[0] = ttx[0];
								queue[tail].x[1] = ttx[1];
								queue[tail].x[2] = ttx[2];
								queue[tail++].len = tlen+1;
							}
						}
					}
					else if(vis[ttx[0]][ttx[1]][0]!=t)
					{
						vis[ttx[0]][ttx[1]][0] = t;
						queue[tail].x[0] = ttx[0];
						queue[tail].x[1] = ttx[1];
						queue[tail].x[2] = 0;
						queue[tail++].len = tlen+1;
					}
				}
			}
			else if(vis[ttx[0]][0][0]!=t)
			{
				vis[ttx[0]][0][0] = t;
				queue[tail].x[0] = ttx[0];
				queue[tail].x[1] = 0;
				queue[tail].x[2] = 0;
				queue[tail++].len = tlen+1;
			}
		}
		if(vis[ex[0]][ex[1]][ex[2]]==t)	return tlen+1;
	}
	return -1;
}
int main()
{
	int i,j,e;
	int ans;
	while(scanf("%d%d%d",&w,&h,&n) && w)
	{
		e = 0;
		for(i = 0; i < h; i++)
		{
			getchar();
			for(j = 0; j < w; j++)
			{
				map[e] = getchar();
				if(map[e] >= 'A' && map[e] <= 'Z')
				{
					ex[map[e]-'A'] = e;
					ey[map[e]-'A'] = e;
				}
				else if(map[e] >= 'a' && map[e] <= 'z')
				{
					sx[map[e]-'a'] = e;
					sy[map[e]-'a'] = e;
				}
				e++;
			}
		}
		if(n < 3)
			sx[2] = sy[2] = ey[2] = ex[2] = 0;
		if(n < 2)
			sx[1] = sy[1] = ey[1] = ex[1] = 0;
		ans = bfs();
		printf("%d\n",ans);
	}
	return 0;
}
