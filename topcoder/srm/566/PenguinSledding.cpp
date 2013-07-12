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
class PenguinSledding {
public:
  long long countDesigns(int n, vector <int> checkpoint1, vector <int> checkpoint2) {
    long long res =  checkpoint1.size() + 1;
    int a[100][100] = {0};
    for (int i = 0; i < checkpoint1.size(); i ++) {
      a[checkpoint2[i]][checkpoint1[i]] = a[checkpoint1[i]][checkpoint2[i]] = 1;
    }

    for (int i = 1; i <= n; i ++)  {
      int k = 0;
      for (int j = 1; j <= n; j ++) k += a[i][j];
      if (k > 1) {
        res += (1LL << k) - k - 1;
      }
    }
    for (int i = 1; i <= n; i ++) {
      for (int j = i + 1; j <= n; j ++) {
        for (int k =j + 1; k <= n; k ++) {
          if (a[i][j] && a[j][k] && a[k][i])
            res ++;
        }
      }
    }
    return res;
  }

};
// BEGIN CUT HERE
int main( int argc, char *argv[] ) {
      {
        int checkpoint1ARRAY[] = {1};
        vector <int> checkpoint1( checkpoint1ARRAY, checkpoint1ARRAY+ARRSIZE(checkpoint1ARRAY) );
        int checkpoint2ARRAY[] = {2};
        vector <int> checkpoint2( checkpoint2ARRAY, checkpoint2ARRAY+ARRSIZE(checkpoint2ARRAY) );
        PenguinSledding theObject;
        eq(0, theObject.countDesigns(2, checkpoint1, checkpoint2),2L);
    }
    {
        int checkpoint1ARRAY[] = {1,2,3};
        vector <int> checkpoint1( checkpoint1ARRAY, checkpoint1ARRAY+ARRSIZE(checkpoint1ARRAY) );
        int checkpoint2ARRAY[] = {2,3,4};
        vector <int> checkpoint2( checkpoint2ARRAY, checkpoint2ARRAY+ARRSIZE(checkpoint2ARRAY) );
        PenguinSledding theObject;
        eq(1, theObject.countDesigns(4, checkpoint1, checkpoint2),6L);
    }
    {
        int checkpoint1ARRAY[] = {1,3,6};
        vector <int> checkpoint1( checkpoint1ARRAY, checkpoint1ARRAY+ARRSIZE(checkpoint1ARRAY) );
        int checkpoint2ARRAY[] = {2,4,4};
        vector <int> checkpoint2( checkpoint2ARRAY, checkpoint2ARRAY+ARRSIZE(checkpoint2ARRAY) );
        PenguinSledding theObject;
        eq(2, theObject.countDesigns(6, checkpoint1, checkpoint2),5L);
    }
    {
        int checkpoint1ARRAY[] = {40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 50, 40, 40, 40,
            23, 4, 24, 40, 22, 40, 8, 40, 40,
            40, 34, 21, 40, 40, 38, 40, 40,
            40, 40, 40, 28, 40, 40, 40, 40,
            46, 13, 40, 40, 40, 47, 40, 40};
        vector <int> checkpoint1( checkpoint1ARRAY, checkpoint1ARRAY+ARRSIZE(checkpoint1ARRAY) );
        int checkpoint2ARRAY[] = {45, 42, 20, 48, 12, 32, 25, 10,
            26, 39, 16, 2, 19, 43, 37, 17,
            19, 19, 19, 18, 19, 27, 19, 29,
            11, 36, 19, 19, 1, 41, 19, 35,
            14, 33, 49, 3, 19, 7, 5, 19, 31,
            19, 19, 6, 9, 15, 19, 44, 30};
        vector <int> checkpoint2( checkpoint2ARRAY, checkpoint2ARRAY+ARRSIZE(checkpoint2ARRAY) );
        PenguinSledding theObject;
        eq(3, theObject.countDesigns(50, checkpoint1, checkpoint2),68719493118L);
    }
    {
        int checkpoint1ARRAY[] = {13, 24, 24, 20, 31, 16, 10, 36, 34, 32,
            28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19,
            21, 8, 1, 26, 27, 25, 15, 22, 30, 30,
            6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18,
            13, 14, 17, 35, 3};
        vector <int> checkpoint1( checkpoint1ARRAY, checkpoint1ARRAY+ARRSIZE(checkpoint1ARRAY) );
        int checkpoint2ARRAY[] = {10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9,
            2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22,
            4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15,
            21, 22, 8, 26, 20, 14, 32, 25, 17, 35,
            8, 36, 26, 23};
        vector <int> checkpoint2( checkpoint2ARRAY, checkpoint2ARRAY+ARRSIZE(checkpoint2ARRAY) );
        PenguinSledding theObject;
        eq(4, theObject.countDesigns(36, checkpoint1, checkpoint2),162L);
    }
    return 0;
}

void eq( int n, long long have, long long need ) {
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
