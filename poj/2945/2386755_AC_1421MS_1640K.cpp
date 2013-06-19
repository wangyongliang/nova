#include<iostream>
#include<map>
#include<string>
#include<memory>
using namespace std;

string name[20000];
int out[20001];
int main()
{
	int n,m,c;
	string str;
	map<string,int> mp;
	while(cin >> n >> m && m+n){
		mp.clear();
		c = 0;
		for(int i = 0; i < n; i++){
			cin >> str;
			if(mp[str] == 0)
				name[c++] = str;
			mp[str]++;
		}
		memset(out,0,sizeof(out));
		for(i = 0; i < c; i++){
			out[mp[name[i]]]++;
		}
		for(i = 1; i <= n; i++)
			cout << out[i] << endl;
	}
	return 0;
}
