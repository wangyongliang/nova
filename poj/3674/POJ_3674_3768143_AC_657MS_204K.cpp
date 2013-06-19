#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a[12];
bool cmp(const int &x,const int &y)
{
	return x>y;
}
int cnt[11];
int ans;
void dfs(int deep,int m)
{
	int index[6],b[6],c[6];
	int i,j,k;
	if(deep==10)
	{
		if(m>a[10].size()) return;
		cnt[10]=m;
		k=0;
		for(i=0;i<11;i++)
		{
			for(j=0;j<cnt[i];j++) 
			{
				b[k]=a[i][j]/10;
				c[k++]=i;
			}
		}
		for(i=0;i<k;i++) index[i]=i;
		do
		{
			j=b[index[0]]*10;
			for(i=1;i<k;i++) j+=b[index[i]]*(10+c[index[i-1]]);
			ans=ans<j?j:ans;
		}
		while(next_permutation(index,index+k));
	}
	else
	{
		for(i=0;i<=a[deep].size()&&i<=m;i++)
		{
			cnt[deep]=i;
			dfs(deep+1,m-i);
		}
	}
}
int main()
{
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<11;i++) a[i].clear();
		for(i=0;i<n;i++) 
		{
			scanf("%d%d",&j,&k);
			a[k].push_back(j);
		}
		for(i=0;i<11;i++) sort(a[i].begin(),a[i].end(),cmp);
		ans=0;
		if(n>6)	dfs(0,6);
		else
		{
			for(i=0;i<11;i++) cnt[i]=a[i].size();
			dfs(10,a[10].size());
		}
		printf("%d\n",ans);
	}
	return 0;
}