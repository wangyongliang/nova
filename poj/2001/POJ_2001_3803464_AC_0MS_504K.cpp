#include<stdio.h>
struct node
{
	int index[26];
	int cnt;
}a[100000];
int n;
void insert(char s[])
{
	int i,j=0;
	for(i=0;s[i];i++)
	{
		if(a[j].index[s[i]-'a']==-1)
		{
			for(int k=0;k<26;k++) a[n].index[k]=-1;
			a[n].cnt=0;
			a[j].index[s[i]-'a']=n++;
		}
		j=a[j].index[s[i]-'a'];
		a[j].cnt++;
	}
}
void find(char s[],char ans[])
{
	int i,j=0;
	for(i=0;s[i];i++)
	{
		ans[i]=s[i];
		j=a[j].index[s[i]-'a'];
		if(a[j].cnt==1) 
		{
			ans[i+1]=0;
			return ;
		}
	}
	ans[i]=0;
}
char str[1100][30];
int main()
{
	int i;
	for(i=0;i<26;i++) a[0].index[i]=-1;
	n=1;
	int m=0;
	while(scanf("%s",str[m])!=EOF)
	{
		insert(str[m]); 
		m++;
	}
	char ans[100];
	for(i=0;i<m;i++)
	{
		find(str[i],ans);
		printf("%s %s\n",str[i],ans);
	}
	return 0;
}