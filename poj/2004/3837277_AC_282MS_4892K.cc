#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
struct node
{
	int index[26];
	int flag;
}a[100000];
int n;
bool flag[23];
int insert(char s[],int m)
{
	int i,j=0;
	for(i=0;s[i];i++)
	{
		if(flag[i]==0) continue;
		if(a[j].index[s[i]-'a']==-1)
		{
			if(m>=0){
			for(int k=0;k<26;k++) a[n].index[k]=-1;
			a[n].flag=-1;
			a[j].index[s[i]-'a']=n++;
			}
			else return -1;
		}
		j=a[j].index[s[i]-'a'];
	}
	if(m>=0)	a[j].flag=m;
	return a[j].flag;
}
int dp[10010];
int pre[10100];
string s[11000];
char s1[100];
bool cmp(const string &a, const string &b ){
	return a.size()<b.size();
}
void print(int m)
{
	if(pre[m]==-1) printf("%s\n",s[m].c_str());
	else
	{
		print(pre[m]);
		printf("%s\n",s[m].c_str());
	}
}
int main()
{
	int i;
	for(i=0;scanf("%s",s1)!=EOF;i++) s[i]=s1;
	int cnt=i;
	sort(s,s+cnt,cmp);
	for(i=0;i<26;i++) a[0].index[i]=-1;
	a[0].flag=-1;
	n=1;
	int k=0,j;
	for(i=0;i<cnt;i++)
	{
		strcpy(s1,s[i].c_str());
		sort(s1,s1+strlen(s1));
		for(j=0;s1[j];j++) flag[j]=1;
		j=insert(s1,-1);
		dp[i]=1;
		pre[i]=-1;
		if(j==-1)
		{
			for(j=0;s1[j];j++) flag[j]=1;
			for(j=0;s1[j];j++)
			{
				flag[j]=0;
				k=insert(s1,-1);
				if(k>=0&&dp[i]<dp[k]+1) 
				{
					dp[i]=dp[k]+1;
					pre[i]=k;
				}
				flag[j]=1;
			}
			insert(s1,i);
		}
	//	printf("%s %d\n",s[i].c_str(),dp[i]);
	}
	for(i=j=0;i<cnt;i++) if(dp[j]<dp[i]) j=i;
	print(j);
	return 0;
}