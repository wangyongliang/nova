#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;
map<int,int> mp[300];
int a[10000000];
char s[1000];
int flag[300];
int cnt[300];
int f(int i,int j)
{
	int k,n;
	if(s[i]>='0'&&s[i]<='9'&&s[j]>='0'&&s[j]<='9')
	{
		for(k=0;i<=j;i++) k=k*10+s[i]-'0';
		return k;
	}
	else
	{
		k=s[i];
		if(flag[s[i]]==0) return -1;
		n=f(i+2,j-1);
		if(flag[k]==0||cnt[k]<=n) return -1;
		n=mp[k][n];
		if(n==0) return -1;
		else return a[n];
	}
}
int main()
{
	int n,k,i,j,m;
	int ans;
	int len;
	while(scanf("%s",s))
	{
		if(s[0]=='.') break;
		for(i=0;i<300;i++)
		{
			mp[i].clear();
			flag[i]=0;
		}
		ans=0;
		m=1;
		for(i=0;;i++)
		{
			len=strlen(s);
			if(s[0]=='.') break;
			if(ans) goto line;
			for(j=0;s[j];j++)
			{
				if(s[j]=='=') break;
			}
			if(s[j]=='=')
			{
				k=f(2,j-2);
				n=f(j+1,strlen(s)-1);
				if(flag[s[0]]==0||k>=cnt[s[0]]||k==-1||n==-1)
				{
					ans=i+1;
					goto line;
				}
				mp[s[0]][k]=m;
				a[m++]=n;
			}
			else
			{
				flag[s[0]]=1;
				k=f(2,strlen(s)-2);
				if(k==-1)
				{
					ans=i+1;
					goto line;
				}
				else
				{
					cnt[s[0]]=k;
				}
			}
line:
			scanf("%s",s);
		}
		printf("%d\n",ans);
	}
	return 0;
}

