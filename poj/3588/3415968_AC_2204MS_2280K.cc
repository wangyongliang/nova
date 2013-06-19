#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef enum {
	downloading=0, waiting, pause, finished
}Status;

string ss[] = { "downloading", "waiting", "paused", "finished" };

void work() {
	int t, n, nD=0;
	bool asc = true;
	
	map<string, Status> dic;
	set<string> st;
	set<string>::iterator it;

	cin >> n >> t;
	for ( int i=0; i<t; i ++ ) {
		string cmd, str;
		cin >> cmd; 
		if ( cmd=="Sort" ) {
			cin >> str;
			if ( str=="asc" ) asc=true;
			else asc=false;
		} else if ( cmd=="New" ) {
			cin >> str;
			if ( nD<n ) {
				dic[str] = downloading;
				nD++;
			} else {
				dic[str] = waiting;
				st.insert(str);
			}

		} else if ( cmd=="Pause" ) {
			cin >> str;

			if ( dic[str]==downloading ) nD--;
			else if ( dic[str]==waiting ){
				it = st.find( str );
				st.erase( it );
			}
			dic[str]=pause;
			if ( st.size()>0 && nD<n ) {
				if (asc) it=st.begin();
				else { it=st.end(); it--; }
				str=*it;
				dic[str] = downloading;
				st.erase(it);
				nD++;
			}

		} else if ( cmd=="Continue" ) {
			cin >> str;
			if (nD<n) {
				dic[str]=downloading;
				nD++;
			} else {
				dic[str]=waiting;
				st.insert(str);
			}			

		} else if ( cmd=="Finish" ) {
			cin >> str;
			dic[str]=finished;
			nD--;
			if ( st.size()>0 ) {
				if (asc) it=st.begin();
				else { it=st.end(); it--; }
				str=*it;
				dic[str] = downloading;
				st.erase(it);
				nD++;
			}
		}
	}

	if ( asc ) {
		map<string, Status>::iterator itt;
		for (itt=dic.begin(); itt!=dic.end(); itt++) {
			cout << itt->first << " " << ss[itt->second] << endl;
		}
	} else {
		map<string, Status>::iterator itt;
		itt=dic.end(); itt--;
		for ( ; itt!=dic.begin(); itt--) {
			cout << itt->first << " " << ss[itt->second] << endl;
		}
		cout << dic.begin()->first << " " << ss[dic.begin()->second] << endl;
	}
	cout << endl;
	return ;
}

int main () {
	int n;
	cin >> n;
	while (n--) work();
	return 0;
}
