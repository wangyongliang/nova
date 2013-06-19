#include<stdio.h>
#include<set>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
set<int> st;
struct node
{
	int index[2];
	int cnt;
}a[100000];
char s[10000000];
int m,n;
void insert(int i,int k)
{
	int j=0;
	int tp;
	for(;i<k;i++)
	{
		tp=s[i]-'0';
		if(a[j].index[tp]==-1)
		{
			a[m].index[0]=a[m].index[1]=-1;
			a[m].cnt=0;
			a[j].index[tp]=m++;
		}
		j=a[j].index[tp];
	}
	a[j].cnt++;
}
void dfs(int k)
{
	if(a[k].cnt)
	{
		st.insert(a[k].cnt);
		while(st.size()>n) st.erase(st.begin());
	}
	if(a[k].index[0]!=-1) dfs(a[k].index[0]);
	if(a[k].index[1]!=-1) dfs(a[k].index[1]);
}
string d[10000];
int num;
void dfs1(int k,int cnt,char str[],int len)
{
	if(a[k].index[1]!=-1)
	{
		str[len]='1';
		dfs1(a[k].index[1],cnt,str,len+1);
	}
	if(a[k].index[0]!=-1)
	{
		str[len]='0';
		dfs1(a[k].index[0],cnt,str,len+1);
	}
	str[len]=0;
	if(cnt==a[k].cnt)
	{
		string str1(str);
		d[num++]=str1;
	}
}
set<int>::iterator it;
bool cmp(const string &str1,const string &str2)
{
	if(str1.length()==str2.length()) return str1>str2;
	else return str1.length()>str2.length();
}
int main()
{
	int i;
	int len;
	int A,B;
	char ans[100];
	while(scanf("%d%d%d",&A,&B,&n)!=EOF)
	{
	//	scanf("%d%d",&A,&B);
		scanf("%s",s);
		len=strlen(s)-1;
		a[0].index[0]=a[0].index[1]=-1;
		a[0].cnt=0;
		m=1;
		for(;A<=B;A++)
		{
			for(i=0;i+A<=len;i++) insert(i,i+A);
		}
		st.clear();
		dfs(0);
		it=st.end();
		it--;
		for(;;it--)
		{
			printf("%d",*it);
			num=0;
			dfs1(0,*it,ans,0);
			sort(d,d+num,cmp);
			for(i=0;i<num;i++) printf(" %s",d[i].c_str());
			printf("\n");
			if(it==st.begin()) break;
		}
	}
	return 0;
}