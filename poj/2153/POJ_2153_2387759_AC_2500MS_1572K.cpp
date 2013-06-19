#include<string>
#include<iostream>
#include<string>
#include<map>

using  namespace std;
char  name[10011][38];
int main()
{
	map<string,int >mp;
	char s[38],str[]={"Li Ming"};
	int n,i,j,t,rank,temp1,temp2;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(name[i]);
		mp[name[i]]=0;
	}
	scanf("%d",&t);
	while (t--)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			getchar();
			gets(s);
			string test(s);
			mp[test]+=j;
		}
		rank=1;
		string test1(str);
		temp1=mp[test1];
		for(i=0;i<n;i++)
		{
			string test2(name[i]);
			temp2=mp[test2];
			if(temp1<temp2&&name[i]!="Li Ming") rank++;
		}
		cout << rank <<endl;
	}
	return 0;
}