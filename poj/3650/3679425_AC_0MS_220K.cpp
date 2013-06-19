#include <iostream>
#include <string>
using namespace std;

int main () {
	while ( true ) {
		string line, ans="";
		char tmp[2]={0};
		if ( !getline(cin, line) ) break;
		if ( line=="#" ) break;
		for ( int p=0; line[p]!='\0'; p++ ) {
			if (line[p]==' ') ans.append("%20");
			else if (line[p]=='!') ans.append("%21");
			else if (line[p]=='$') ans.append("%24");
			else if (line[p]=='%') ans.append("%25");
			else if (line[p]=='(') ans.append("%28");
			else if (line[p]==')') ans.append("%29");
			else if (line[p]=='*') ans.append("%2a");
			else {
				tmp[0]=line[p]; ans.append(tmp);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

