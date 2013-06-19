#include <stdio.h>
#include <memory.h>

#define min(a,b) ((a) > (b) ? (b) : (a))

#define maxn 1001

int n,m,ans,low[maxn],dfn[maxn], flag[maxn], stack[maxn],top, bcc[maxn], nbcc;
bool hates[maxn][maxn], hate[maxn][maxn], vis[maxn], used[maxn], bipart,f[maxn];

void mark(int v, int f)
{
     used[bcc[v]] = true;
     flag[bcc[v]] = f;
     for (int i=0; i<nbcc; i++)
     {
         if (bcc[v] != bcc[i] && !used[bcc[i]] && ! hates[bcc[v]][bcc[i]])
         {
             mark(i,-f);
         }
         else if (bcc[v] != bcc[i] && used[bcc[i]] && ! hates[bcc[v]][bcc[i]] && flag[bcc[v]] == flag[bcc[i]])
         {
              bipart = false;
              return;
         }
     }
}

void dfs(int v, int d)
{
    int i,u;
    low[v] = dfn[v] = d;
    stack[top++] = v;
    vis[v] = true;
    for (i=1; i<=n; i++)
    {
        if (i!=v && !hate[v][i])
        {
            hate[i][v] = hate[v][i] = true;
            if (!vis[i])
            {
                dfs(i,d+1);
                low[v] = min(low[v],low[i]);
                if (dfn[v] <= low[i])
                {
                    nbcc = 0;
                    while (stack[top-1] != i)
                    {
                        bcc[nbcc++] = stack[top-1];
                        top--;
                    }
                    bcc[nbcc++] = stack[top-1];
                    top--;
                    bcc[nbcc++] = v;
                    memset(used,false,sizeof(used));
                    memset(flag,0,sizeof(flag));
                    bipart = true;
                    mark(0,1);
                    if (bipart || nbcc==1)
                    {
                    }
                    else
                    {
                        for (int j=0; j<nbcc; j++)
                            f[bcc[j]] = 1;
                    }
                }
            }
            else
            {
                low[v] = min(low[v], dfn[i]);
            }
        }
    }
}

int main()
{
    int a,b,i;
    while (scanf("%d%d",&n,&m) && n+m)
    {
          memset(hates,false,sizeof(hates));
          memset(vis, false,sizeof(vis));
          memset(hate,false,sizeof(hate));
          for (i=0; i<m; i++)
          {
              scanf("%d%d",&a,&b);
              hates[a][b] = hates[b][a] = true;
              hate[a][b] = hate[b][a] = true;
          }
          ans = 0;
          memset(f,0,sizeof(f));
          for (i=1; i<=n; i++)
          {
              if(!vis[i])
              {
                  top = 0;
                  nbcc = 0;
                  dfs(i,0);
              }
          }
          ans = 0;
          for (i=1; i<=n; i++)
              if (f[i]) ans++;
          printf("%d\n",n-ans);
    }
    return 0;
}
