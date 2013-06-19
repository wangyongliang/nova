#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define maxn 10000
using namespace std;
vector<int> a[maxn],b[maxn],ans[maxn];
int n;
int index[maxn],flag[maxn];
vector<int> q1,q2;
void dfs1(int x)
{
	flag[x]=1;
	int i;
	for(i=0;i<a[x].size();i++)
	{
		if(flag[a[x][i]]==0)
		{
			dfs1(a[x][i]);
		}
	}
	q1.push_back(x);
}
void dfs2(int x)
{
	flag[x]=2;
	int i;
	for(i=0;i<b[x].size();i++)
	{
		if(flag[b[x][i]]==1)
		{
			dfs2(b[x][i]);
		}
	}
	q2.push_back(x);
}
int cnt;
void scc()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		flag[i]=0;
		index[i]=-1;
	}
	cnt=0;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			q1.clear();
			dfs1(i);
			for(j=q1.size()-1;j>=0;j--)
			{
				if(flag[q1[j]]==1)
				{
					q2.clear();
					dfs2(q1[j]);
					sort(q2.begin(),q2.end());
					for(k=0;q2[k]<n;k++) index[q2[k]]=cnt;
					for(;k<q2.size();k++) ans[cnt].push_back(q2[k]);
				//	sort(ans[cnt].begin(),ans[cnt].end());
					cnt++;
				}
			}
		}
	}
}
bool flg[maxn][maxn];
int main()
{
	int i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++){
			a[i].clear(),b[i].clear();
			flag[i]=0;
			ans[i].clear();
			for(j=0;j<maxn;j++) flg[i][j]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&j);
				j--;
				flg[i][j]=1;
				a[i].push_back(j+n);
				b[j+n].push_back(i);
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			j--;
			a[j+n].push_back(i);
			b[i].push_back(j+n);
		}
		scc();
	//	cout<<"OK"<<endl;
	//	for(i=0;i<n;i++) cout<<index[i]<<"  "<<ans[i].size()<<endl;
	//	system("pause");
		vector<int> tp;
		for(i=0;i<n;i++)
		{
			tp.clear();
	//		printf("%d",ans[index[i]].size())
				;
			for(j=0;j<ans[index[i]].size();j++) 
			{
			//		printf(" %d",ans[index[i]][j]-n+1);
				if(flg[i][ans[index[i]][j]-n]) tp.push_back(ans[index[i]][j]);
			}
			printf("%d",tp.size());
			for(j=0;j<tp.size();j++) printf(" %d",tp[j]-n+1);

			printf("\n");
		}
	}
	return 0;
}