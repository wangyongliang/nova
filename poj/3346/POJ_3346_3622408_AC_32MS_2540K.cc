#include <stdio.h>
#include <string.h>
const int maxn = 101;
typedef struct Node
{
    int x,y,dys,tot;
}Node;
int num,sx,sy;
char map[maxn][maxn];
int ans[27][maxn][maxn], start[maxn*4][2], num_s;
int n,m;
Node Q[maxn*maxn*200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool chk(int x, int y)
{
    return (x>=0 && x<n && y>=0 && y<m && (map[x][y]=='.' || map[x][y]=='$' || (map[x][y]>='1' && map[x][y]<='9')));
}
int Read()
{
    num_s = num = n = m = 0;
    gets(map[n]);
    if (map[n][0] == map[n][1] && map[n][1] == '-') return 0;
    n++;
    while (gets(map[n]) && strlen(map[n]) != 0) 
          n++;
    m = strlen(map[0]);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (map[i][j] == '$')
            {
               sx = i; sy = j;
            }
            else if (map[i][j] == '#')
            {
                start[num_s][0] = i;
                start[num_s++][1] = j;
            }
            else if (map[i][j]>='A' && map[i][j]<='Z')
            {
                 start[num_s][0] = i;
                 start[num_s++][1] = j;
                 if (map[i][j] - 'A' + 1 > num)
                 {
                     num = map[i][j] - 'A' + 1;
                 }
            }
        }
    }
    return 1;
}
int BFS()
{
    int i,k,x,y,px,py,ret=0x7FFFFFFF;
    int head =0, tail = 0;
    Node T;
    memset(ans,-1,sizeof(ans));
    for (i=0; i<num_s; i++)
    {
        int t = map[start[i][0]][start[i][1]] == '#' ? 0 : map[start[i][0]][start[i][1]]-'A'+1;
        for (int j=0; j<=t; j++)
        {
            ans[j][start[i][0]][start[i][1]] = 0;
            Q[tail].x = start[i][0];
            Q[tail].y = start[i][1];
            Q[tail].dys = j;
            Q[tail++].tot = 0;
        }
    }
    while (head < tail)
    {
        T = Q[head++];
        if (map[T.x][T.y] == '$') continue;
		if (ans[T.dys][T.x][T.y]<T.tot) continue;
        for (i=0; i<4; i++)
        {
            x = T.x + dx[i];
            y = T.y + dy[i];
            if (!chk(x,y)) continue;
            if (map[T.x][T.y] == '.' || map[T.x][T.y] == '#' || (map[T.x][T.y]>='A'&& map[T.x][T.y]<='Z'))
            {
                if (ans[T.dys][x][y]<0 || ans[T.dys][x][y]>T.tot)
                {
                    ans[T.dys][x][y]=T.tot;
                    Q[tail].x = x;
                    Q[tail].y = y;
                    Q[tail].dys = T.dys;
                    Q[tail++].tot = T.tot;
                }
            }
            else
            {
				if (ans[T.dys][x][y]<0 || ans[T.dys][x][y]>T.tot + map[T.x][T.y]-'0')
				{
					ans[T.dys][x][y] = T.tot + map[T.x][T.y] - '0';
					Q[tail].x = x;
					Q[tail].y = y;
					Q[tail].tot = ans[T.dys][x][y];
					Q[tail++].dys = T.dys;
				}
				if (T.dys>0 && (ans[T.dys-1][x][y]<0 || ans[T.dys-1][x][y]>T.tot))
				{
					ans[T.dys-1][x][y] = T.tot;
					Q[tail].x = x;
					Q[tail].y = y;
					Q[tail].tot = ans[T.dys-1][x][y];
					Q[tail++].dys = T.dys-1;
				}
     
            }
        }
    }
    for (i=0; i<=num; i++)
    {
        if (ans[i][sx][sy]>=0 && ret > ans[i][sx][sy])
        {
            ret = ans[i][sx][sy];
        }
    }
    return ret!=0x7FFFFFFF ? ret : -1;
}
int main()
{
    while (Read())
    {
        int ans = BFS();
        if (ans<0)
        {
            puts("IMPOSSIBLE");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}

