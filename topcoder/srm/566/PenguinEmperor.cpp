// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

vector<string> split( const string &s, const string &delim = " " ) {vector<string> res; string t;for (int i = 0 ; i != s.size() ; i++ ) {if (delim.find( s[i] ) != string::npos ) {if (!t.empty()) {res.push_back( t );t = "";}} else {t += s[i];}}if (!t.empty()) res.push_back(t);return res;}
vector<int> splitInt( const string &s, const string &delim = " " ) {vector<string> tok = split(s, delim); vector<int> res;for (int i = 0 ; i != tok.size(); i++ ) res.push_back(atoi(tok[i].c_str()));return res;}

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print(T a) {cerr << a;}
void print(long long a ) {cerr << a << "L";}
void print(string a ) {cerr << '"' << a << '"';}
template<typename T> void print(vector<T>);
template<typename T> void eq(int, T, T);
void eq(int, long long, long long);
template<typename T> void eq(int, vector<T>, vector<T>);
void eq(int, string, string);
// END CUT HERE
#define maxn 360
long long dp[maxn][maxn];
long long cache[maxn];
long long mod = 1000000007LL;
long long ans[maxn];
long long tmp[maxn];
long long p[maxn];
int n;
void copy(long long A[], long long B[]) {
  for (int i = 0; i < n; i ++)
    A[i] = B[i];
}
void mul(long long A[], long long B[], long long C[]) {
  for (int i = 0; i < n; i ++)
    A[i] = 0;
  for (int i = 0; i < n; i ++) {
    if (B[i] == 0)
      continue;
    for (int j = 0; j < n; j ++) {
      if (C[j] == 0) continue;
      int k = (j - i + n) % n;
      A[k] += B[i] * C[j];
      // if (A[k] >= mod)
      //   A[k] -= mod;
      A[k] %= mod;
    }
  }
}

void pow(long long A[], long long k) {
  for (int i = 0; i < n; i ++)
    ans[i] = 0;
  ans[0] = 1;
  while (k) {
    if (k % 2) {
      mul(tmp, ans, A);
      copy(ans, tmp);
    }
    mul(tmp, A, A);
    copy(A, tmp);
    k /= 2;
  }
}

class PenguinEmperor {
public:
  int countJourneys(int nn, long long m) {
    int res = 0;
    n = nn;
    for (int i = 0; i < maxn; i ++) {
      for (int j = 0; j < maxn; j ++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1LL;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < n; j ++) {
        if (dp[i][j] > 0) {
          int next1 = (j + i + 1) % n;
          dp[i + 1][next1] += dp[i][j];
          dp[i + 1][next1] %= mod;
          int next2 = (j - i - 1 + 2 * n) % n;
          if (next2 != next1) {
            dp[i + 1][next2] += dp[i][j];
            dp[i + 1][next2] %= mod;
          }
        }
      }
    }

    for (int i = 0; i <n; i ++) {
      cache[i] = dp[m % n][i];
    }
    pow(dp[n], m/n);
    mul(tmp, cache, ans);
    return tmp[0];
  }
};
// BEGIN CUT HERE
int main( int argc, char *argv[] ) {
    // {
    //     PenguinEmperor theObject;
    //     eq(0, theObject.countJourneys(3, 2LL),2);
    // }
    // {
    //     PenguinEmperor theObject;
    //     eq(1, theObject.countJourneys(4, 3LL),2);
    // }
    // {
    //     PenguinEmperor theObject;
    //     eq(2, theObject.countJourneys(5, 36LL),107374182);
    // }
    // {
    //     PenguinEmperor theObject;
    //     eq(3, theObject.countJourneys(300, 751LL),413521250LL);
    // }
    // {
    //     PenguinEmperor theObject;
    //     eq(4, theObject.countJourneys(300, 750LL),0);
    // }
    {
        PenguinEmperor theObject;
        eq(5, theObject.countJourneys(350, 1000000000000000000LL),667009739LL);
    }
    // {
    //     PenguinEmperor theObject;
    //     eq(6, theObject.countJourneys(5, 7LL),12);
    // }
    return 0;
}
void eq( int n, long long have, long long need ) {
  if (have == need) {
    cerr << "Case " << n << " passed." << endl;
  } else {
    cerr << "Case " << n << " failed: expected ";
    print(need);
    cerr << " received ";
    print(have);
    cerr << "." << endl;
  }
}
void eq( int n, string have, string need ) {
  if ( have == need ) {
    cerr << "Case " << n << " passed." << endl;
  } else {
    cerr << "Case " << n << " failed: expected ";
    print( need );
    cerr << " received ";
    print( have );
    cerr << "." << endl;
  }
}

template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
  if ( have.size() != need.size() ) {
    cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
    print( have );
    print( need );
    return;
  }
  for ( int i = 0; i < have.size(); i++ ) {
    if ( have[i] != need[i] ) {
      cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
      print( have );
      print( need );
      return;
    }
  }
  cerr << "Case " << n << " passed." << endl;
}

template<typename T> void eq( int n, T have, T need ) {
  if ( have == need ) {
    cerr << "Case " << n << " passed." << endl;
  } else {
    cerr << "Case " << n << " failed: expected ";
    print( need );
    cerr << " received ";
    print( have );
    cerr << "." << endl;
  }
}

template<typename T> void print( vector<T> a ) {
  cerr << "{";
  for ( int i = 0 ; i != a.size() ; i++ ) {
    if ( i != 0 ) cerr << ", ";
    print( a[i] );
  }
  cerr << "}" << endl;
}
// END CUT HERE
