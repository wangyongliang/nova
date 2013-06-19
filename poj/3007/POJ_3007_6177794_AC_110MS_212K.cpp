#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[77];
char map[800][77];
int p[800];
int cnt;

void fun_reverse(char *s,char *t)
{
	int len=strlen(s),i;
	for(i=0;i<len;i++)
		t[len-1-i]=s[i];
	t[len]='\0';
}

void combine(char *s,char *t)
{
	int l1=strlen(s),l2=strlen(t),i;
	for(i=0;i<l1;i++)
		map[cnt][i]=s[i];
	for(i=l1;i<l1+l2;i++)
		map[cnt][i]=t[i-l1];
	map[cnt][i]='\0';
	cnt++;
}

bool cmp(int x,int y)
{
	return strcmp(map[x],map[y])>0;
}
/*
bool cmp( char *s, char *t)
{
	int i;
	for(i=0;s[i];i++)
	{
		if(s[i]!=t[i])
			return s[i]<t[i];
	}
	return 1;
}
*/
int main()
{
	int m,i,j,l;
	char s[75],s1[75],s2[75],s1rev[75],s2rev[75];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",s);
		cnt=0;
		l=strlen(s);
		for(i=0;i<=l;i++)
		{
			for(j=0;j<i;j++)
				s1[j]=s[j];
			s1[j]='\0';
			for(j=i;j<l;j++)
				s2[j-i]=s[j];
			s2[j-i]='\0';
			fun_reverse(s1,s1rev);
			fun_reverse(s2,s2rev);
			combine(s1,s2);
			combine(s1rev,s2);
			combine(s1,s2rev);
			combine(s1rev,s2rev);
			combine(s2,s1);
			combine(s2,s1rev);
			combine(s2rev,s1);
			combine(s2rev,s1rev);
		}
		for(i=0;i<cnt;i++)
		{
			p[i]=i;
		}
		sort(p,p+cnt,cmp);
		int ans=1;
		for(i=1;i<cnt;i++)
		{
			if(strcmp(map[p[i]],map[p[i-1]])!=0)
				ans++;
		}
	//	ans--;
		if(ans==0) ans=1;
		printf("%d\n",ans);
	}
	return 0;
}
