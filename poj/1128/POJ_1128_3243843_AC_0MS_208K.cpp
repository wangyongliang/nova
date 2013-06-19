#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
char s[30][30];
int a[30][30];
int x[30][2],y[30][2];
int cnt;
int in[30],flag[30];
vector<string> ans;
void dfs(string str)
{
	if(str.size()==cnt)
	{
		reverse(str.begin(),str.end());
		ans.push_back(str);
	}
	else
	{
		int i,j;
		char ch;
		int flg[30];
		string str1;
		for(i=26;i>=0;i--)
		{
			if(flag[i]==1&&in[i]==0)
			{
				for(j=0;j<26;j++)
				{
					if(a[i][j]) flg[j]=1,in[j]--;
					else flg[j]=0;
				}
				ch=i+'A';
				flag[i]=-1;
				str1=str+ch;
				dfs(str1);
				for(j=0;j<26;j++) in[j]+=flg[j];
				flag[i]=1;
			}
		}
	}
}
int main()
{
	int i,j;
	int k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<30;i++)
		{
			flag[i]=-1;
			y[i][0]=x[i][0]=1000;
			y[i][1]=x[i][1]=0;
			in[i]=0;
			for(j=0;j<30;j++) a[i][j]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]>='A'&&s[i][j]<='Z') 
				{
					k=s[i][j]-'A';
					flag[k]=1;
					if(x[k][0]>i) x[k][0]=i;
					if(x[k][1]<i) x[k][1]=i;
					if(y[k][0]>j) y[k][0]=j;
					if(y[k][1]<j) y[k][1]=j;
				}
			}
		}
		for(i=0;i<26;i++)
		{
			if(flag[i]==-1) continue;
			for(j=x[i][0];j<=x[i][1];j++)
			{
				if(s[j][y[i][0]]!='A'+i) a[s[j][y[i][0]]-'A'][i]=1;
				if(s[j][y[i][1]]!='A'+i) a[s[j][y[i][1]]-'A'][i]=1;
			}	
			for(j=y[i][0];j<=y[i][1];j++)
			{
				if(s[x[i][0]][j]!='A'+i) a[s[x[i][0]][j]-'A'][i]=1;
				if(s[x[i][1]][j]!='A'+i) a[s[x[i][1]][j]-'A'][i]=1;
			}
		}
		cnt=0;
		for(i=0;i<26;i++)
		{
			if(flag[i]==1) cnt++;
			for(j=0;j<26;j++) if(a[i][j]) in[j]++;
		}
		string str;
		ans.clear();
		str="";
		dfs(str);
		sort(ans.begin(),ans.end());
		for(i=0;i<ans.size();i++) printf("%s\n",ans[i].c_str());
	}
	return 0;
}
