#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class t
{
	string s1,s2;
	int len1,len2;
	int i,j;
public:
	void init(string s,string ss) 
	{
		s1=s,s2=ss;
		len1=s1.size();
		len2=s2.size();
	}
	void J()
	{
		i=len1;
		char temp=s1[i-1];
		for(i--;i>0;i--) s1[i]=s1[i-1];
		s1[0]=temp;
	}
	void C()
	{
		char temp=s1[0];
		for(i=0;i<len1-1;i++) s1[i]=s1[i+1];
		s1[len1-1]=temp;
	}
	void E()
	{
		j=len1/2+len1%2;
		for(i=0;j<len1;j++,i++) swap(s1[i],s1[j]);
	}
	void A()
	{
		i=0,j=len1-1;
		while(i<j)
		{
			swap(s1[i],s1[j]);
			i++;
			j--;
		}
	}
	void P()
	{
		for(i=0;i<len1;i++)
		{
			if(s1[i]>='0'&&s1[i]<='9')
			{
				if(s1[i]=='9') {s1[i]='0';continue;}
				s1[i]++;
			}
		}
	}
	void M()
	{
		for(i=0;i<len1;i++)
		{
			if(s1[i]>='0'&&s1[i]<='9')
			{
				if(s1[i]=='0'){s1[i]='9';continue;}
				s1[i]--;
			}
		}
	}
	void work()
	{
		int i=len2-1;
		while(i>=0)
		{
			switch(s2[i])
			{
			case 'J':J();break;
			case 'C':C();break;
			case 'P':M();break;
			case 'A':A();break;
			case 'M':P();break;
			case 'E':E();break;
			}
			i--;
		}
	//	cout<<"\nthe ans is:\n"<<endl;
		cout<<s1<<endl;
	}
};
int main()
{
	t a;
	int n;
	string s1,s2;
	scanf("%d",&n);
	while(n--)
	{
		cin>>s1>>s2;
		a.init(s2,s1);
		a.work();
	}
	return 0;
}