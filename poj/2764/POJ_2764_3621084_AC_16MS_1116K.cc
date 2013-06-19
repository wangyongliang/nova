/* Solution to "Unequalled Consumption"
 *
 * The solution is by Lagrange interpolation and binary search.
 *
 * Complexity: O(n^2*(lcm(v_1,...,v_n) + q*v_1*log(P)))
 *
 * Author: Per Austrin
 *
 *
 * Solution:
 *
 * Let w_1, ... w_n be the weights of the candy types (as in the
 * problem statement).  Let F_k(m) be the number of different candy
 * boxes that can be made with total weight m, using only the first k
 * candy types.  What we're after is the smallest positive m such that
 * F_n(m) >= P.  The typical DP solution for this problem would be to
 * utilize the recurrence F_k(m) = F_k(m-w_k) + F_{k-1}(m) and then
 * compute F_n(m) for increasingly higher values of m until F_n(m) >=
 * P, but this won't work, because P is too big, and the answer can be
 * even bigger than P (though not by much).
 *
 * Let M = lcm(w_1, ...,w_n), and define P_{k, r}(x) = F_k(x*M + r).
 * The key observation (which I think is the most difficult part of
 * the entire problem) is that P_{k,r}(x) is in fact a polynomial of
 * degree k-1.  Thus, it is determined by its values on x = 0...k-1,
 * which correspond to evaluations of F_k on values between 0 and k*M
 * (assuming 0 <= r < M).  These values can be computed using DP,
 * since k*M <= n*M <= 25200.  For large values of x, P_{k,r}(x) (and
 * by extension F_k(m)) can be computed using e.g. Lagrange
 * interpolation.
 *
 * One small problem still remains: even though we can quickly compute
 * the number of different chocolate boxes for a specific weight, we
 * don't want to test all weights in order to find the smallest which
 * yields P different boxes.  However, from the recurrence used for
 * the DP it is easy to see that for values of m with a fixed residue
 * r moduli w_k, F_k(m) is non-decreasing.  Thus, we can simply do one
 * binary search for each possible value of r, finding the smallest m
 * for each residue, and then picking the overall smallest as our
 * answer.
 *
 * The only case when the answer is impossible is when n = 1 and P > 1.
 *
 */

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>

const long long maxans = 100000000000000001LL;

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> T abs(T a)      { return a < 0 ? -a : a; }

int n, mod, v[10];
long long wtbl[20000][5];

// standard dp solution for small weights
long long ways_brute(int c, int x) {
  if (x < 0) return 0;
  if (c == 0) return x % v[0] == 0;
  if (wtbl[x][c-1] == -1)
    wtbl[x][c-1] = ways_brute(c-1, x) + ways_brute(c, x-v[c]);
  return wtbl[x][c-1];
}

// lagrange interpolation for big weights
long long ways(long long x) {
  int r = x % mod;
  long long k = x / mod, res = 0;
  if (k < n) return ways_brute(n-1, x);
  for (int i = 0; i < n; ++i) {
    long long num = ways_brute(n-1, r + mod*i), den = 1, d;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
	num *= k-j;
	den *= i-j;
	d = gcd(abs(num), abs(den));
	num /= d;
	den /= d;
      }
    }
    if (den < 0) num = -num, den = -den;
    assert(den == 1);
    res += num;
  }
  return res;
}

int main(void) {
  int cse = 0, q;
  while (scanf("%d", &n) == 1 && n) {
    printf("Set %d\n", ++cse);

    mod = 1;
    for (int i = 0; i < n; ++i) {
      scanf("%d", v+i);
      mod = lcm(mod, v[i]);
    }
    memset(wtbl, -1, sizeof(wtbl));

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      long long res = maxans, P;
      scanf("%I64d", &P);

      // ways(n) is not increasing, hence we cannot apply a binary
      // search straight off, but ways(n) is increasing for n with a
      // fixed residue modulo any of the weights, so we do one binary
      // search for each residue mod v[0].
      for (int i = 0; i < *v; ++i) {
	long long lo = -1, hi = 2;
	// first find a range for the binary search
	while ((lo+1) * *v + i < res && ways(hi * *v + i) < P)
	  lo = hi, hi <<= 1;
	if ((lo+1) * *v + i >= res) continue;

	while (hi - lo > 1) {
	  long long m = (lo + hi)/2, w = ways(m * *v + i);
	  if (w < P) lo = m;
	  else hi = m;
	}
	// don't allow zero, we want positive answers.
	if (hi * *v + i == 0) ++hi;
	res <?= hi * *v + i;
      }

      if (res == maxans) printf("no candy for you\n");			     
      else printf("%I64d\n", res);
    }
  }
  return 0;
}
