#include<stdio.h>
#include<map>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
map<string,int> mp;
int ptr[30];
void init(){
ptr[0] = 2;
ptr[1] = 5;
ptr[2] = 4;
ptr[3] = 4;
ptr[4] = 1;
ptr[5] = 6;
ptr[6] = 5;
ptr[7] = 5;
ptr[8] = 1;
ptr[9] = 7;
ptr[10] = 6;
ptr[11] = 3;
ptr[12] = 5;
ptr[13] = 2;
ptr[14] = 3;
ptr[15] = 5;
ptr[16] = 7;
ptr[17] = 2;
ptr[18] = 1;
ptr[19] = 2;
ptr[20] = 4;
ptr[21] = 6;
ptr[22] = 6;
ptr[23] = 7;
ptr[24] = 5;
ptr[25] = 7;
}

bool flag[300]={0};
int main()
{
	char s[10],s1[10];
	scanf("%s",s);
	sort(s,s+strlen(s));
	int i,j,k;
	for(i=0;i<s[i];i++) flag[s[i]]=1;
	init();
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
	for(i=0;i<(1<<n);i++)
	{
		for(j=0;j<(1<<n);j++)
		{
			if(i&j) continue;
			str1=str2="";
			for(k=0;k<n;k++)
			{
				if(i&(1<<k)) str1+=s[k];
				if(j&(1<<k)) str2+=s[k];
			}
			ans=mp[str1]+mp[str2];
			max=max<ans?ans:max;
			
		}
	}
	printf("%d\n",max);
	return 0;
}
