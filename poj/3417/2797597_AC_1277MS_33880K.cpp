#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define size 100100
vector <int> a[size];
int b[size];
int n,cnt,m;
int A[size*4],B[size*4];
int R[size];
bool flag[size];
int M[size*4][32];
__int64 ans;
void dfs(int deep,int i,int j)
{
	A[cnt]=deep;
	B[cnt]=i;
	R[i]=cnt;
	flag[j]=0;
	cnt++;
	vector<int >::iterator it;
	for(it=a[i].begin();it!=a[i].end();it++)
	{
	
		if(flag[*it])
		{
			dfs(deep+1,*it,i);
			A[cnt]=deep;
			B[cnt]=i;
			cnt++;
		}
	}
}
void InitRMQ()
{
	int i,j;
	cnt=0;
	dfs(0,1,0);
	for (i=0; i<cnt; i++)
		M[i][0] = i;
	for (j=1; (1<<j)<=cnt; j++)
	{
		for (i=0; i+(1<<j)-1<cnt; i++)
		{
			if (A[M[i][j-1]] > A[M[i+(1<<(j-1))][j-1]])
				M[i][j] = M[i+(1<<(j-1))][j-1];
			else
				M[i][j] = M[i][j-1];
		}
	}
}
void f(int i,int j)
{
	vector<int> ::iterator it;
	flag[i]=0;
	for(it=a[i].begin();it!=a[i].end();it++)
	{
		if(j!=*it)
		{
			f(*it,i);
		}
	}
	for(it=a[i].begin();it!=a[i].end();it++)
	{
		if(*it!=j) b[i]+=b[*it];
	}
	if(b[i]==0) ans+=m;
	else if(b[i]==1) ans++;
}
int RMQ(int i, int j)
{
	int k = 0;
	while ((1<<(k+1)) < (j-i+1)) k++;
	if (A[M[i][k]] > A[M[j-(1<<k)+1][k]])
		return B[M[j-(1<<k)+1][k]];
	else
		return B[M[i][k]];
}
int main()
{
	int i,j,k,p;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(k=0;k<=n;k++) 
		{
			a[k].clear();
			flag[k]=1;b[k]=0;
		}
		for(k=1;k<n;k++) 
		{
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			a[j].push_back(i);
		}
		cnt=0;
		InitRMQ();
		p=m;
		while(p--)
		{
			scanf("%d%d",&i,&j);
			if(i==j) continue;
			if(R[i]>R[j]) swap(i,j);
			k=RMQ(R[i],R[j]);
			b[i]++;
			b[j]++;
			b[k]-=2;
		}
		ans=0;
		f(1,0);
		ans-=m;
		printf("%I64d\n",ans);
	}
	return 0;
}