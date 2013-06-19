#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 1000000000;
const int MAXV = 105;
const int MAXI = 1005;
const int MAXL = 20;
int N, V, T, S, E;
int change [MAXI];
int dist [MAXL][MAXV][MAXV];
int best [MAXV], best2 [MAXV];
inline void check (int &ind)
{
    if (change [ind] == -1)
        change [ind] = V++;

    ind = change [ind];
}
int main () 
{
    memset (change, -1, sizeof (change));
    memset (dist, 63, sizeof (dist));
    memset (best, 63, sizeof (best));
    scanf ("%d %d %d %d", &N, &T, &S, &E);
    check (S);
    check (E);
    for (int i = 0; i < T; i++)
	{
        int A, B, L;
        scanf ("%d %d %d", &L, &A, &B);
        check (A);
        check (B);
        dist [0][A][B] <?= L;
        dist [0][B][A] <?= L;
    }
    for (int p = 1; (1 << p) <= N; p++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist [p - 1][i][j] < INF)
                    for (int k = 0; k < V; k++)
                        if (dist [p - 1][i][j] + dist [p - 1][j][k] < dist [p][i][k])
                            dist [p][i][k] = dist [p - 1][i][j] + dist [p - 1][j][k];
    best [S] = 0;
    for (int p = 0; (1 << p) <= N; p++)
        if (N & (1 << p)) {
            memset (best2, 63, sizeof (best2));
            for (int i = 0; i < V; i++)
                if (best [i] < INF)
                    for (int j = 0; j < V; j++)
                        if (best [i] + dist [p][i][j] < best2 [j])
                            best2 [j] = best [i] + dist [p][i][j];
            memcpy (best, best2, sizeof (best2));
        }
    printf ("%d\n", best [E]);

    return 0;
}

