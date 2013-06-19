#include<stdio.h>
#include<map>
#include<string>
using namespace std;
map<string,int> mp;
char s[1000]={0};
int main()
{
	int i=0,ans,n;
	char ch;
	while(ch=getchar())
	{
		if(ch==EOF) break;
		if(ch!='\n')
		{
			s[i++]=ch;
		}
	}
	n=i;
	ans=0;
	mp.clear();
	string str;
	for(i=0;i<n;)
	{
		ans++;
		str="";
		if(s[i]==' ') i++;
		if(s[i]==96||s[i]==39)
		{
			str=s[i];
			if(s[i+1]==s[i]) i+=2,str+=s[i];
			else i+=1;
			if(str!="")	mp[str]=1;
		}
		else if(s[i]=='f')
		{
			str="";
			str+=s[i];
			if(s[i+1]=='f')
			{
				str+=s[i];
				if(s[i+2]=='i'||s[i+2]=='l') str+=s[i+2],i+=3;
				else i+=2;
			}
			else if(s[i+1]=='i'||s[i+1]=='l') 
			{
				str+=s[i+1];
				i+=2;
			}
			else i++;
			if(str!="")	mp[str]=1;
		}
		else 
		{
			str="";
			if(s[i]!=' ') str+=s[i];
			i++;
			if(str!="")	mp[str]=1;
		}
	}
	printf("%d\n",mp.size());
	return 0;

}