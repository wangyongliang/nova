#include<stdio.h>
#include<vector>
#define max 100100
using namespace std;
vector <int> a[max];
int b[max],t[max];
bool flag[max];
int ans[max];
int n,s;
void dfs(int i,int fa)
{
	b[i]=s;
	s++;
	vector<int>::iterator it;
	for(it=a[i].begin();it!=a[i].end();it++)
	{
		if(*it!=fa)
		{
			dfs(*it,i);
		}
	}
	t[i]=s-1;
}
int lowbit(int i)
{
	return i&(i^(i-1));
}
int sum(int i)
{
	int an=0;
	while(i>0)
	{
		an+=ans[i];
		i-=lowbit(i);
	}
	return an;
}
void jia(int i)
{
	while(i<=n)
	{
		ans[i]++;
		i+=lowbit(i);
	}
}
void jian(int i)
{
	while(i<=n)
	{
		ans[i]--;
		i+=lowbit(i);
	}
}
int main()
{
	int i,j,q;
	char c;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++) 
		{
			a[i].empty();
			flag[i]=1;
			ans[i]=lowbit(i);
		}
		ans[0]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&j,&q);
			a[j].push_back(q);
		//	a[q].push_back(j);
		}
		s=1;
		dfs(1,0);
		scanf("%d",&q);
		getchar();
		while(q--)
		{
			scanf("%c%d",&c,&i);
			getchar();
			if(c=='Q')
			{
				j=sum(t[i]);
				j-=sum(b[i]-1);
				printf("%d\n",j);
			}
			else
			{
				if(flag[i])
				{
					flag[i]=0;
					jian(b[i]);
				}
				else
				{
					flag[i]=1;
					jia(b[i]);
				}
			}
		}
	}
	return 0;
}
