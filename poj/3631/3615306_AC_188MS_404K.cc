#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_m = 10000;
const int MAX_n = 10000;

int m, n;
int H1[MAX_m], H2[MAX_m];
int T[MAX_n];

int assign(int i) {
    if (T[H1[i]] == -1) {
        T[H1[i]] = i; 
        return 1;
    } else if (T[H2[i]] == -1) {
        T[H2[i]] = i; 
        return 1;
    } else {
        int q = i;
        int p = H1[q];
        while (true) {
            int r = T[p];
            T[p] = q;
            if (r == -1) return 1;
            p = H1[r] + H2[r] - p;
            q = r;
            if (q == i && p == H1[q]) return 0;
        }
    }
}

int solve() {
    fill_n(T, n, -1);
    for (int q = 0; q < m; q++) {
        if (!assign(q)) return 0;
    }
    return 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &n);
        for (int q = 0; q < m; q++) {
            scanf("%d %d", &H1[q], &H2[q]);
        }
        if (solve()) printf("successful hashing\n");
        else         printf("rehash necessary\n");
    }
}
