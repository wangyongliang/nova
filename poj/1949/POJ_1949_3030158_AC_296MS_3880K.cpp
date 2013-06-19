#include<stdio.h>
#include<vector>
#define maxn 10000+10
using namespace std;
vector <int > a[maxn];
vector< int>::iterator it;
int t[maxn],n,b[maxn],cnt[maxn],m;
int main()
{
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			a[i].clear();
			t[i]=0;
			scanf("%d%d",&b[i],&j);
			cnt[i]=j;
			while(j--)
			{
				scanf("%d",&k);
				a[k].push_back(i);
			}
		}
		m=n;
		while(m)
		{
			for(i=1;i<=n;i++)
			{
				if(cnt[i]==0)
				{
					t[i]+=b[i];
					cnt[i]=-1;
					for(it=a[i].begin();it!=a[i].end();it++)
					{
						cnt[*it]--;
						if(t[*it]<t[i]) t[*it]=t[i];
					}
					m--;
				}
			}
		}
		for(i=1,j=0;i<=n;i++)
		{
			j=t[i]>j?t[i]:j;
		}
		printf("%d\n",j);
	}
	return 0;
}