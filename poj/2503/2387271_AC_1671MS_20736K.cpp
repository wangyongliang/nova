#include<iostream>
#include<string.h>
#include<map>
#include<string>
#include<memory>
using namespace std;
string word1[100010];
string word2[100010];
int main()
{
	string str1,str2;
	int n;
	map<string,string> mp;
	mp.clear();
	while(1)
	{
		cin>>str1;
		char c = getchar();
		if(c == ' '){
			cin>>str2;
			mp[str2]=str1;
		}
		else
			break;
	}	
	if(mp[str1] != "")
		cout << mp[str1] << endl;
	else 
		cout << "eh" << endl;
	while(cin >> str1)
	{
		if(mp[str1] != "")
			cout<< mp[str1] << endl;
		else
			cout << "eh" << endl;
	}
	return 0;
}
