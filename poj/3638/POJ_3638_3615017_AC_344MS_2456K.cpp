#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>

using namespace std;

#ifndef INFINITY
#define INFINITY 1e30
#endif

const int MAX_h = 1000;

double X[MAX_h]; // Coordinates of houses
double Me[MAX_h+1][MAX_h+1]; // Memoisation of error()
double Ms[MAX_h+1][MAX_h+1]; // Memoisation of solve()

double error(int i, int j) {
    if (Me[i][j] != -1.0) return Me[i][j];
    double e = 0.0;
    for (int k = i + 1; k < j; k++) {
        e += abs(X[k] - (X[i] + (k - i) * (X[j] - X[i])/(j-i)));
    }
    return Me[i][j] = e;
}

double solve(int h, int c, int d=0) {
    if (Ms[h][c] != -1.0) return Ms[h][c];
    if (c == 2) return Ms[h][c] = error(0, h-1);
    else {
        double mine = 1e20;
        for (int j = c-2; j < h-1; j++) {
            mine = min(mine, solve(j+1, c-1, d+1) + error(j, h-1));
        }
        return Ms[h][c] = mine;
    }
}

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        int h, c; scanf("%d %d", &h, &c);
        for (int i = 0; i < h; i++) {
            scanf("%lf", &X[i]);
        }
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j <= h; j++) {
                Me[i][j] = Ms[i][j] = -1.0;
            }
        }
        printf("%.4lf\n", solve(h, c) / h);
    }
}
