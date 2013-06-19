#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 1 << 28;

const int MAX_m = 20;
const int MAX_n = 20;

int memo[1 << MAX_n];
char S[MAX_m+1];
char Sr[MAX_m+1];
char T[MAX_n+1];
int m, n;

/*
 * Find the longest match for T[i..i+g] in A of length e
 */
int match(int i, int g, char* A, int e) {
    int longest = 0;
    for (int k = 0; k < e; k++) {
        int h = 0;
        while (h < g && k+h < e && A[k+h] == T[i+h]) h++;
        longest = max(longest, h);
    }
    return longest;
}

/*
 * found is a bitmask giving which symbols have already been copied.
 */
int solve(unsigned int found) {
    if (memo[found] != -1) {
        return memo[found];
    }
    // Let U be the string found so far,
    // and Ur its reverse
    char U[MAX_n+1];
    char Ur[MAX_n+1];
    fill(U,  U +n, 0);
    fill(Ur, Ur+n, 0);
    for (int i = 0; i < n; i++) {
        if (found & 1 << i) U[i] = T[i];
    }
    reverse_copy(U, U+n, Ur);
    int best = INF; // The number of copy operations needed
    int last_h = 0;
    for (int i = 0; i < n; i++) {
        int g = 0; // The length of the missing piece starting at T[i..]
        while (i + g < n && !(found & 1 << i+g)) g++;
        if (g == 0) {
            last_h = 0;
            continue;
        }
        int h = 0; // The longest match for T[i..i+g]
        h = max(h, match(i, g, S,  m)); // copied from S
        h = max(h, match(i, g, Sr, m)); // reversed from S
        h = max(h, match(i, g, U,  n)); // copying from T
        h = max(h, match(i, g, Ur, n)); // reversed from T
        if (h == 0) return INF; // Nothing matches T[i..] at all
        if (h > last_h - 1) { // If not, we cannot improve
            // Set bits from i+h downto i
            int newfound = found | (1 << i+h)-1 ^ (1 << i)-1;
            best = min(best, 1 + solve(newfound));
        } 
        if (best == INF) break; // Nothing can be filled in here
        last_h = h;
    }
    memo[found] = best;
    return best;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", S);
        m = strlen(S);
        reverse_copy(S, S+m, Sr);
        scanf("%s", T);
        n = strlen(T); 
        fill(memo, memo + (1 << MAX_n), -1);
        memo[(1 << n) - 1] = 0;
        int s = solve(0);
        if (s == INF) printf("impossible\n");
        else          printf("%d\n", s);
    }
}
