#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MAX_N 100

int N, M, K, map[MAX_N+2][MAX_N+2]={0};

int lsize(int i, int j) {
    int a = 1;          /* this square gets single count */
    map[i][j] = 0;
    if (map[i][j-1]) a += lsize(i,j-1);
    if (map[i][j+1]) a += lsize(i,j+1);
    if (map[i-1][j]) a += lsize(i-1,j);
    if (map[i+1][j]) a += lsize(i+1,j);
    return a;
}

int main(void) {
    int i, j, k, best=0;
    scanf ("%d %d %d", &N, &M, &K);
    for (k=0; k<K; k++) {
       scanf ("%d %d", &i, &j);
        map[i][j] = 1;
    }
    for (i=1; i<=N; i++)
	{
		for (j=1; j<=M; j++)
		{   if (map[i][j]){
			k=lsize(i,j);
                best = MAX (best, k);
		}
		}
	}

 printf ("%d\n", best);
  return 0;
}
