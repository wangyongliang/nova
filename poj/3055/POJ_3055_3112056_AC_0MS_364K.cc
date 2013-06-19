using namespace std;

#include <iostream>
#include <vector>
#include <string>

int friends (string n1, string n2) {
  vector<int> d1(10,0), d2(10,0);
  for (int i=0; i<n1.size(); i++) d1[n1[i]-'0']=1;
  for (int i=0; i<n2.size(); i++) d2[n2[i]-'0']=1;
  for (int i=0; i<10; i++) if (d1[i]!=d2[i]) return 0;
  return 1;
}

int almost (string n1, string n2) {
  string old=n1;
  
  for (int i=0; i<(int)n1.size()-1; i++) {
    if (n1[i]>'0' && n1[i+1]<'9') {
      if (i==0 && n1[i]=='1') continue;
      n1[i]--;
      n1[i+1]++;
      if (friends(n1,n2)) return 1;
      n1=old;
    }
    if (n1[i]<'9' && n1[i+1]>'0') {
      n1[i]++;
      n1[i+1]--;
      if (friends(n1,n2)) return 1;
      n1=old;
    }
  }
  
  return 0;
}

int main () {

  int runs;
  cin>>runs;
  while (runs--) {
    string n1,n2;
    cin>>n1>>n2;

    if (friends(n1,n2))
      cout << "friends" << endl;
    else if (almost(n1,n2) || almost(n2,n1))
      cout << "almost friends" << endl;
    else
      cout << "nothing" << endl;
  }

  return 0;
}
