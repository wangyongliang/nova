#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
#define maxn 300
int c[maxn][maxn],f[maxn][maxn],s,t,n;
vector<int> p[maxn];
int max_flow()
{
	int i,j,ans=0,min;
	int flag[maxn][3];
	for(i=0;i<maxn;i++)
	{
		for(j=0;j<maxn;j++) f[i][j]=0;
	}
	queue<int> q;
	vector<int>::iterator it;
	while(1)
	{
		while(q.size()) q.pop();
		for(i=0;i<maxn;i++) flag[i][0]=0;
		q.push(s);
		flag[s][0]=1;
		flag[s][1]=0;
		flag[s][2]=0x7fffffff;
		while(q.size()&&!flag[t][0])
		{
			i=q.front();
			q.pop();
			for(it=p[i].begin();it!=p[i].end();it++)
			{
				j=*it;
				if(!flag[j][0]&&(c[i][j]>f[i][j]||f[j][i]))
				{
					flag[j][0]=1;
					q.push(j);
					if(c[i][j]>f[i][j])
					{
						flag[j][1]=i;
						flag[j][2]=flag[i][2]>c[i][j]-f[i][j]?c[i][j]-f[i][j]:flag[i][2];
					}
					if(f[j][i])
					{
						flag[j][1]=-i;
						flag[j][2]=flag[i][2]>f[j][i]?f[j][i]:flag[i][2];
					}
				}
			}
		}
		if(flag[t][0])
		{
			i=t;
			ans+=flag[t][2];
			j=flag[t][1];
			while(i!=s)
			{
				if(j>0) f[j][i]+=flag[t][2];
				else f[i][-j]-=flag[t][2];
				i=j>0?j:-j;
				j=flag[i][1];
			}
		}
		else return ans;
	}
}
int main()
{
	int b[maxn][4],i,j,tt,sum;
	double d,l;
//	freopen("testdata.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&tt);
	vector<int> ans;
	while(tt--)
	{
		ans.clear();
		scanf("%d %lf",&n,&d);
		d*=d;
		sum=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<4;j++) scanf("%d",&b[i][j]);
			sum+=b[i][2];
		}
		for(i=0;i<maxn;i++)
		{
			p[i].clear();
			for(j=0;j<maxn;j++) c[i][j]=f[i][j]=0;
		}
		s=n*2+1;
		for(i=1;i<=n;i++)
		{
			c[s][i]=b[i][2];
			c[i][i+n]=b[i][3];
			for(j=i+1;j<=n;j++)
			{
				l=pow((b[i][0]-b[j][0]),2)+pow((b[i][1]-b[j][1]),2);
				if(l<d)
				{
					c[i+n][j]=0x7fffffff;
					c[j+n][i]=0x7fffffff;
				}
			}
		}
		for(i=1;i<=s;i++)
		{
			for(j=1;j<=s;j++)
			{
				if(j!=i&&c[i][j])
				{
					p[i].push_back(j);
					p[j].push_back(i);
				}
			}
		}
		for(t=1;t<=n;t++)
		{
			i=max_flow();
			if(i==sum) ans.push_back(t-1);
		}
		if(ans.size())
		{
			printf("%d",ans[0]);
			for(i=1;i<ans.size();i++) printf(" %d",ans[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
