#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
bool cmp(const char * &c,const char * &b)
{
	return strcmp(c,b)>0?1:0;
}
int main()
{
	int i,j,n;
	char s[32];
	double rat;
	map<string,int> mp;
	map<string,int>::iterator it;
	mp.clear();
	i=0;
	while(gets(s)!=NULL)
	{
		string name(s);
		mp[name]++;
		i++;
	}
	//sort(a,a+i-1,cmp);
	for(it=mp.begin();it!=mp.end();it++)
	{
		//string name1(a[i]);
		//rat=mp[name1]*1.0/i;
		cout<<(*it).first;
		rat=(* it).second;
		printf(" %.4lf\n",(*it).second*1.0*100 / i);
	}
	return 0;
}