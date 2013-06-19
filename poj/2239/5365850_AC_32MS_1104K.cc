/*crackerwang*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(X,Y) (X)>(Y)?(X):(Y)
#define ABS(X)  (x)>0?(x):-(x)
#define ps system("pause")

int  n,m;
bool flag[310];
int link[310];
int a[310][310];
int find(int x)
{
	int i;
	for(i=0;i<m;i++)	
	{
		if(flag[i]==0&&a[x][i])
		{
			flag[i]=1;
			if(link[i]==-1||find(link[i]))
			{
				link[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{	
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		int t;
		for(i=0;i<n;i++)
		{
			for(j=0;j<310;j++) a[i][j]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&t)	;
			while(t--)
			{
				int p,q;
				scanf("%d%d",&p,&q);
				a[i][(p-1)*12+q-1]=1;
			}
		}
		m=7*12;
		for(i=0;i<m;i++) 
		{
			flag[i]=0;
			link[i]=-1;
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) flag[j]=0;
			if(find(i)) ans++;
		}
		printf("%d\n",ans);
	}
	ps;
	
	return 0;
}
