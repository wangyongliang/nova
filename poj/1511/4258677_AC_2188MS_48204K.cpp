#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
#define N 1000005
#define MAXF 1000000000
struct edge
{
    int a, b;
    int w;
    int next;
    edge(int aa, int bb, int ww, int nn)
    {
        a = aa;
        b = bb;
        w = ww;
        next = nn;
    }
    edge()
    {
    }
};
edge ET1[N], ET2[N];
int EH1[N], EH2[N], n;
long long dist[N];
bool inQ[N];

void spfa(int s, int *EH, edge *ET)
{
    queue<int> Q;
    memset(inQ, 0, sizeof(inQ));
    fill(dist, dist + N, MAXF);
    dist[s] = 0;
    inQ[s] = 1;
    Q.push(s);
    while (!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        inQ[k] = 0;
        for (int p = EH[k]; p != -1; p = ET[p].next)
        {
            long long t = ET[p].b, w = ET[p].w;
            if (dist[k] + w < dist[t])
            {
                dist[t] = dist[k] + w;
                if (!inQ[t])
                {
                    inQ[t] = 1;
                    Q.push(t);
                }
            }
        }
    }
}

void addedge(int a, int b, int w, int *tot, edge *ET, int *EH)
{
    ET[*tot] = edge(a, b, w, EH[a]);
    EH[a] = *tot;
    (*tot)++;
}

void solve()
{
    int m, i, a, b, w, tot1, tot2;
    long long sum = 0;
    memset(EH1, -1, sizeof EH1);
    memset(EH2, -1, sizeof EH2);
    tot1 = tot2 = 0;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        /* 分别建立正向和反向图 */
        scanf("%d %d %d", &a, &b, &w);
        addedge(a, b, w, &tot1, ET1, EH1);
        addedge(b, a, w, &tot2, ET2, EH2);
    }
    /* 分两次调用spfa，累加其结果 */
    spfa(1, EH1, ET1);
    for (i = 1; i <= n; i++)
        sum += dist[i];
    spfa(1, EH2, ET2);
    for (i = 1; i <= n; i++)
        sum += dist[i];
    printf("%lld\n", sum);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}