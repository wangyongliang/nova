#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<stdio.h>
using namespace std;
map <string, int> mp;
struct node
{
	string s;
	int cnt;
}a[200];
bool cmp(const node &x,const node &y)
{
	if(x.cnt ==y.cnt) return x.s<y.s;
	else return x.cnt>y.cnt;
}
int main()
{
//	string s[200];
	int i,j,n,m=1;
	char temp[300];
	mp.clear();
	while(1)
	{
		gets(temp);
		//getchar();
		string str(temp);
		if(temp[0]=='0') break;
		else if(temp[0]>='A'&&temp[0]<='Z')
		{
			a[m].s=str;
			a[m++].cnt=0;
		}
		else if(temp[0]>='a'&&temp[0]<='z')
		{
			string str2(temp);
			if(mp[str2]==0) 
			{
				a[m-1].cnt++;
				mp[str2]=m-1;
			}
			else if(mp[str2]==m-1);
			else if(mp[str2]<m-1)
			{
				a[mp[str2]].cnt--;
				mp[str2]=10000;
			}
		}
		else if(temp[0]=='1')
		{
			sort(a+1,a+m,cmp);
			for(i=1;i<m;i++)
			{
				cout<<a[i].s<<' '<<a[i].cnt<<endl;
			}
			mp.clear();
			m=1;
		}
	}
	return 0;
}