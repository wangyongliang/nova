/*
  [BAPC'06] BOOKSORT
  by: Jan Kuipers
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

int N;

long long id (vector<int> x) {
  long long res=0;
  for (int i=0; i<N; i++)
    res = N*res + x[i];
  return res;
}

map<long long,int> dist (vector<int> x) {

  map<long long,int> res;
  res[id(x)]=0;

  queue<vector<int> > q;
  q.push(x);

  while (!q.empty()) {
    x = q.front(); q.pop();
			
    for (int fr=0; fr<N; fr++)
      for (int to=fr+1; to<=N; to++)
	for (int sh=1; sh<=N-to; sh++) {
	  vector<int> y=x;
	  for (int i=fr; i<to; i++) y[i+sh]=x[i];
	  for (int i=0; i<sh; i++) y[fr+i]=x[to+i];

	  if (res.count(id(y))) continue;
	  if ((res[id(y)] = res[id(x)]+1) < 2) q.push(y);
	}
  }
  
  return res;	
}

int main () {

  int runs;
  cin>>runs;
  while (runs--) {

    cin>>N;
    vector<int> book(N);
    for (int i=0; i<N; i++) cin>>book[i];

    vector<int> book2 = book;
    sort(book2.begin(),book2.end());
    for (int i=0; i<N; i++)
      for (int j=0; j<N; j++)
	if (book[i]==book2[j]) { book[i]=j; book2[j]=j; }
    
    map<long long,int> d1 = dist(book);
    map<long long,int> d2 = dist(book2);

    int res=5;
    for (map<long long,int>::iterator it=d1.begin(); it!=d1.end(); it++) 
      if (d2.count(it->first)) res<?=it->second+d2[it->first];

    if (res<5) 
      cout << res << endl;
    else
      cout << "5 or more" << endl;
  }
  
  return 0;
}
