#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int a[20][20],b[20][20],flag[20][20];
int cnt;
int n,m;
string ans;
int dx[]={0,0,1,-1,0};
int dy[]={1,-1,0,0,0};
void f(int x,int y)
{
	int i;
	int xx,yy;
	for(i=0;i<5;i++)
	{
		xx=dx[i]+x;
		yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<m) b[xx][yy]++;
	}
}
void dfs(int deep)
{
	int i,j;
	string str;
	if(deep+1==n) 
	{
		int sum=0;
		str="";
		for(i=0;i<m;i++) 
		{
			if(a[deep][i]!=(b[deep][i]%2)) return;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				sum+= flag[i][j];
				char ch=flag[i][j]+'0';
				str+=ch;
			}
		}
		if(sum<cnt||(sum==cnt&&str<ans)) cnt=sum,ans=str;
	}
	else
	{
		for(i=0;i<m;i++)
		{
			if(a[deep][i]!=(b[deep][i]%2))
			{
				flag[deep+1][i]=1;
				f(deep+1,i);
			}
		}
		dfs(deep+1);
	}
}
int main()
{	
	int i,j,k;
	
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) scanf("%d",&a[i][j]);
		}
		cnt=100000;
		for(i=0;i<(1<<m);i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<m;k++) b[j][k]=flag[j][k]=0;
			}
			k=i;
			for(j=0;j<m;j++,k/=2) 
			{
				flag[0][j]=k%2;
				if(flag[0][j]) 
					f(0,j);
			}
			dfs(0);
		}
		if(cnt==100000) printf("IMPOSSIBLE\n");
		else
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++) 
				{
					if(j) printf(" ");
					printf("%c",ans[k++]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}