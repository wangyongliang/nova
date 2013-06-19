#include<iostream>
#include<algorithm>
#include<string>
//#include<cstring>

using namespace std;
int a[100];
void check(int len)
{
	int i,j;
	if(a[0]==2) 
	{
		a[0]=0;
		a[1]+=1;
	}
	for(i=1;i<len;i++)
	{
		if(a[i]>0&&a[i-1]>0)
		{
			a[i]--;
			a[i-1]--;
			a[i+1]++;
		}
		if(a[i]>=2)
		{
			if(i==1)
			{
				a[0]++;
				a[1]-=2;
				a[2]++;
			}
			else
			{
				a[i]-=2;
				a[i+1]++;
				a[i-2]++;
			}
		}
	}
}
string str1,str2;
string atostr()
{
	int i;
	for(i=99;i>=0&&a[i]==0;i--);
	if(i<0) return "0";
	string ans="";
	for(;i>=0;i--)
	{
		ans+=(char)(a[i]+'0');
	}
	return ans;
}
void tofi()
{
	int i;
			while(1)
		{
			for(i=0;i<100;i++)
			{
				if(a[i]>=2||(i-1>=0&&a[i]>0&&a[i-1]>0)) break;
			}
			if(i==100) break;
			check(100);
		}
}
int main()
{
	int i,j;
	string str1,str2;
//	freopen("a.out","w",stdout);
	while(cin>>str1>>str2)
	{
		while(str1[0]=='0') str1=str1.substr(1,str1.size()-1);
		while(str2[0]=='0') str2=str2.substr(1,str2.size()-1);
		if(str1=="") str1="0";
		if(str2=="") str2="0";
		reverse(str1.begin(),str1.end());
		reverse(str2.begin(),str2.end());		
		memset(a,0,sizeof(a));
		for(i=0;i<str1.size();i++)
		{
			if(str1[i]=='1') a[i]++;
		}
		tofi();
		str1=atostr();
		memset(a,0,sizeof(a));
		for(i=0;i<str2.size();i++)
		{
			if(str2[i]=='1') a[i]++;
		}
		tofi();
		str2=atostr();
		memset(a,0,sizeof(a));
				reverse(str1.begin(),str1.end());
		reverse(str2.begin(),str2.end());	
		for(i=str2.size()-1;i>=0;i--){
			if(str2[i]=='1') a[i]++;
		}
		for(i=str1.size()-1;i>=0;i--){
			if(str1[i]=='1') a[i]++;
		}
		tofi();
		string str3=atostr();
				reverse(str1.begin(),str1.end());
		reverse(str2.begin(),str2.end());	
		while(str1.size()!=str3.size())
		{
			str1=' '+str1;
		}
		while(str2.size()!=str3.size())
		{
			str2=' '+str2;
		}
		cout<<"  "<<str1<<endl;
		cout<<"+ "<<str2<<endl;
		cout<<"  ";
		for(i=0;i<str3.size();i++) cout<<"-";
		cout<<endl;
		cout<<"  "<<str3<<endl<<endl;
	//	cout<<str3<<endl;
	
	}
	return 0;
}