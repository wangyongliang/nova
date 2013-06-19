#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
//vector<int> a[200][2];
set<int> a[200][2];
int flag[200][2];
int n,m;
char s[200][20];
int f(int k,int flg)
{
	int i;
	set<int>::iterator it1,it2;
	for(i=0;i<m;i++)
	{
		it1=a[i][0].find(k);
		it2=a[i][1].find(k);
		if(it1!=a[i][0].end()&&a[i][1].end()!=it2)
		{
			if(s[i][0]!='=') return 0;
		}
		else if(it1==a[i][0].end()&&it2!=a[i][1].end())
		{
			if(flg)
			{
				if(s[i][0]!='<') return 0;
			}
			else 
			{
				if(s[i][0]!='>') return 0;
			}
		}
		else if(it1!=a[i][0].end()&&it2==a[i][1].end())
		{
			if(flg) 
			{
				if(s[i][0]!='>') return 0;
			}
			else
			{
				if(s[i][0]!='<') return 0;
			}
		}
		else 
		{
			if(s[i][0]!='=') return 0;
		}
	}
	return 1;
}

int main()
{
	int cnt;
	int k,j,i;
	//char s[10];
	//scanf("%s",s+1);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<m;i++)
		{
			int cnt;
			scanf("%d",&cnt);
			a[i][0].clear();
			a[i][1].clear();
			for(j=0;j<cnt;j++)
			{
				scanf("%d",&k);
				a[i][0].insert(k);
			}
			for(j=0;j<cnt;j++)
			{
				scanf("%d",&k);
				a[i][1].insert(k);
			}
			scanf("%s",s[i]);
		}
		for(i=1;i<=n;i++)
		{
			flag[i][0]=f(i,0);
			flag[i][1]=f(i,1);
		}
		int ans=0,tp;
		for(i=1;i<=n;i++)
		{
			if(flag[i][0]||flag[i][1])		ans++,tp=i;
		}
		if(ans==1) printf("%d\n",tp);
		else printf("0\n");
	}
	return 0;
}