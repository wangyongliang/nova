#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 1000000
int n;
struct node
{
	int index[26];
	int flag;
}a[maxn];

void init()
{
	int i;
	n=1;
	for(i=0;i<26;i++) a[0].index[i]=-1;
	a[0].flag=0;
}


int find(int begin,int end,char s[])
{
	int i,j=0;
	for(i=begin;i<=end;i++)
	{
		if(a[j].index[s[i]-'a']==-1) return 0;
		j=a[j].index[s[i]-'a'];
	}
	return a[j].flag;
}
void insert(char s[])
{
	int i,j=0,k;
	for(i=0;s[i];i++)
	{
		if(a[j].index[s[i]-'a']==-1)
		{
			for(k=0;k<26;k++) a[n].index[k]=-1;
			a[j].index[s[i]-'a']=n;
			a[n].flag=0;
			n++;
		}
		j=a[j].index[s[i]-'a'];
	}
	a[j].flag=1;
}
char ans[500];
int cnt=100000;
int q[500],back[500][2],flag[300][2];
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
/*
int abs(int x)
{
	if(x>0)return x;
	else return -x;
}
*/
void f(char s[])
{
	int dp[300][2],back[300][2];
	int i,j;
	int inf=100000;
	int len=strlen(s);
	for(i=0;i<len;i++) dp[i][0]=dp[i][1]=inf;
	if(find(0,0,s)) 
	{
		dp[0][0]=1;
		back[0][0]=-inf;
	}
	for(i=1;i<len;i++)
	{
		if(find(0,i,s)) 
		{
			dp[i][1]=1;
			back[i][1]=-inf;
		}
		if(dp[i-1][1]<inf&&find(i,i,s))
		{
			dp[i][0]=dp[i-1][1]+1;
			back[i][0]=(i-1);
		}
		for(j=0;j+1<i;j++)
		{
			if((min(dp[j][0],dp[j][1])+1<dp[i][1])&&find(j+1,i,s))
			{
				if(dp[j][0]<dp[j][1])
				{
					dp[i][1]=dp[j][0]+1;
					back[i][1]=-j;
				}
				else
				{
					dp[i][1]=dp[j][1]+1;
					back[i][1]=j;
				}
			}
		}
	}
	if(min(dp[len-1][0],dp[len-1][1])>=cnt) return;
	if(min(dp[len-1][0],dp[len-1][1])*2>=len) return;
	cnt=min(dp[len-1][0],dp[len-1][1]);
	if(dp[len-1][0]<dp[len-1][1]) i=1-len;
	else i=len-1;
	j=0;
	int k=0,l;
	while(1)
	{
		if(i<=0) j=abs(back[abs(i)][0]);
		else j=abs(back[abs(i)][1]);
		if(j==inf) break;
		for(l=abs(i);l>j;l--) ans[k++]=s[l];
		ans[k++]=' ';
		if(i<=0) i=back[-i][0];
		else i=back[i][1];
	}
	for(j=abs(i);j>=0;j--) ans[k++]=s[j];
	ans[k]=0;
	reverse(ans,ans+k);	
}

int main()
{
	int i,k,kk;
	init();
	char s[300];
	char tp[300];
	int ct;
	while(gets(s))
	{
		if(strlen(s)==0) break;
		for(i=0;s[i];i++)
		{
			if(s[i]<'a'||s[i]>'z') break;
		}
		if(i==strlen(s))	insert(s); 
	}
	//while(1);
	while(gets(s))
	{
		if(strlen(s)==1&&s[0]=='0') break;
		ct=100000;
		for(k=0;k<26;k++)
		{
			cnt=100000;
			ans[0]=0;
			for(i=0;s[i];i++)
			{
				s[i]++;
				if(s[i]>'z') s[i]='a';
			}
			f(s);
			if(cnt<ct)
			{
				ct=cnt;
				strcpy(tp,ans);
				kk=k;
			}
		}
line:
		if(ct<100000) printf("k=%d: %s\n",kk,tp);
		else printf("NO SOLUTIONS\n");
	}
	return 0;
}