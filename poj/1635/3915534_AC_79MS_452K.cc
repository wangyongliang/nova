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
		if(tp1==tp2) printf("same\n");
		else printf("different\n");
	}
	return 0;
}