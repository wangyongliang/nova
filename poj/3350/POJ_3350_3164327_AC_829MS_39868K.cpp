#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
using namespace std;
#define PINS 20000
#define BALLS 500
#define NIL -1
int pins[PINS];
int sums[PINS];
int cache[PINS][BALLS];
int n, balls, w;
 
static inline int max(int a, int b) { return a > b ? a : b; }
 
int solve(int g, int b) {
    // p(g, b) = max(p(g+1, b), p(g+w, b+1)+sum(g,g+w), { k=0..w-1 }{ sum(g,g+w)+sum(g+w,g+w+k)+p(g+w+k+1, b+2) })
    if(g>=n || b>=balls) return 0;
    if(cache[g][b] != NIL) return cache[g][b];
 
    int score;
    int k, add;
    score = max(solve(g+1, b), solve(g+w, b+1)+sums[g]);
    for(add=0, k=0; (k < w-1) && (b+1 < balls); k++) {
        add += pins[g+w+k];
        score = max(score, sums[g] + add + solve(g+w+k+1, b+2));
    }
    return cache[g][b] = score;
}
 
int main() {
 
    int i, j, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &balls, &w);
        memset(sums, 0, sizeof(sums));
        memset(pins, 0, sizeof(pins)); 
        n += w;
        for(i=0;i<PINS;i++) for(j=0;j<BALLS;j++) cache[i][j] = NIL;
        for(i=w;i<n;i++)    scanf("%d", &pins[i]); 
        for(i=n-1;i>=0;i--) sums[i] = sums[i+1] + pins[i] - pins[i+w]; 
        printf("%d\n", solve(0, 0));
    } 
    return 0;
}
