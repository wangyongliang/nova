/*#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string f(string str1)
{
	string ans,a[1600];
	int cnt0,cnt1,i,k=0;
	if(str1.size()<2) return str1;
	else
	{
		cnt0=cnt1=0;
		string tp;
		tp="";
		for(i=0;i<str1.size();i++)
		{
			if(str1[i]=='0') cnt0++;
			else cnt1++;
			tp+=str1[i];
			if(cnt0==cnt1)
			{
				string tpp;
				tpp=tp.substr(1,tp.size()-2);
				tp=f(tpp);
				tp='0'+tp+'1';
				a[k++]=tp;
				tp="";
			}

		}
		sort(a,a+k);
		tp="";
		for(i=0;i<k;i++) tp+=a[i];
		return tp;
	}
}
char s1[30000],s2[30000];
int main()
{
	string str1,str2;
	string ans1,ans2;
	//vector<string> ans(10);
	//printf("%d\n",ans.size());
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1,s2);
		str1=s1;
		str2=s2;
		ans1=f(str1);
		ans2=f(str2);
		if(ans1==ans2) printf("same\n");
		else printf("different\n");
	}
	return 0;
}
*/


/*
#include <stdio.h>
#include<stdlib.h>
int h[9999];
char s[9999],t[9999],*p;
int hash(int j)
{
   int sum=h[j+5000];
   while (*p && *p++=='0')
        sum=(sum+h[j]*hash(j+1)) % 19001;
    return ((sum*sum) % 19001);
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<9999;i++)
        h[i]=rand()%19001;
    while (n--)
    {
        scanf("%s%s",s,t);
        p=s;
        i=hash(0);
        p=t;
        printf("%s\n",i==hash(0)?"same":"different");
        //可以多次hash，避免冲突      
    }
     return 0;
}
*/
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int a=1003,p=1007,q=19001,b=1001;
char s[10000];
int f(int st,int en)
{
	vector<int> tp;
	tp.clear();
	int ans=a;
	if(st+1==en) return (a*b)%q;
	else
	{
		int i,cnt0,cnt1;
		cnt0=cnt1=0;
		int min=st;
		for(i=st;i<=en;i++)
		{
			if(s[i]=='0') cnt0++;
			else cnt1++;
			if(cnt0==cnt1)
			{
				tp.push_back(f(min+1,i-1));
				min=i+1;
			}
		}
		sort(tp.begin(),tp.end());
		for(i=0;i<tp.size();i++)
		{
			ans=(ans*p^tp[i])%q;
		}
		return (ans*b)%q;
	}
}
int main()
{
	int t,len;
	scanf("%d",&t);
	int tp1,tp2;
	int len1,len2;
	while(t--)
	{
		scanf("%s",s);
		tp1=f(0,strlen(s)-1);
		len1=strlen(s);
		scanf("%s",s);
		tp2=f(0,strlen(s)-1);
		len2=strlen(s)-1;
	//	if(len1!=len2) while(1);
	//	printf("%d %d\n",tp1,tp2);
		if(tp1==tp2) printf("same\n");
		else printf("different\n");
	}
	return 0;
}