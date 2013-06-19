#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
map<string,int> mp;
int ptr[30]={2,5,4,4,1,6,5,5,1, 7,6,3,5,2,3, 5,7,2,1,2, 4, 6, 6, 7, 5, 7,};

bool flag[300]={0};
int main()
{
		int i,j,k;
	char s[10],s1[10];
	scanf("%s",s);
	sort(s,s+strlen(s));
	for(i=0;s[i];i++) flag[s[i]]=1;
	while(scanf("%s",s1))
	{
		if(s1[0]=='.') break;
		sort(s1,s1+strlen(s1));
		for(j=i=0;s1[i];i++) 
		{
			j+=ptr[s1[i]-'a'];
			if(flag[s1[i]]==0) break;
		}
		if(s1[i]) continue;
		string str=s1;
		mp[str]=j;
	}
	int n=strlen(s);
	string str1,str2;
	int ans=0;
	int max=0;
	int cnt=1;
	for(i=0;i<n;i++) cnt*=3;
	for(i=0;i<cnt;i++)
	{
			str1=str2="";
			j=i;
			for(k=0;k<n;k++)
			{
				if(j%3==1) str1+=s[k];
				if(j%3==2) str2+=s[k];
				j/=3;
			}
			ans=mp[str1]+mp[str2];
			max=max<ans?ans:max;			
	}
	printf("%d\n",max);
	return 0;
}
