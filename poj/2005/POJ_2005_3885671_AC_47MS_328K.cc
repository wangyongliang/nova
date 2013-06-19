#include<stdio.h>
#include<algorithm>
using namespace std;
int f(char ch1,char ch2)
{
	if(ch1>ch2) swap(ch1,ch2);
	int ans=0;
	if(ch1=='A'&&ch2=='A') return 12;
	if(ch2>='0'&&ch2<='9') ans+=ch2-'0';
	else 
	{
		if(ch2!='A')ans+=10;
		else ans+=11;
	}
	if(ch1>='0'&&ch1<='9') ans+=ch1-'0';
	else 
	{
		if(ch1!='A')ans+=10;
		else ans+=11;
	}
	return ans;
}


char s[]={"A23456789TJQK"};
int flag[300];
int main()
{
	int i;
	int n;
	char s1[2],s2[2],s3[2];
	double ans,tp;
	int t=0;
	while(scanf("%d",&n)&&n)
	{
		ans=0.0;
		scanf("%s%s%s",s1,s2,s3);
		for(i=0;s[i];i++) flag[s[i]]=4*n;
		flag[s1[0]]--;
		flag[s2[0]]--;
		flag[s3[0]]--;
		int y=f(s2[0],s3[0]);
		for(i=0;s[i];i++)
		{
			int x=f(s[i],s1[0]);
			if(y>x)
			{
				tp=n*52-3;
				tp=flag[s[i]]/tp;
				ans+=tp;
			}
		}	
		//if(t++) printf("\n");
		printf("%.3lf%%\n\n",ans*100);
	}
	return 0;
}
