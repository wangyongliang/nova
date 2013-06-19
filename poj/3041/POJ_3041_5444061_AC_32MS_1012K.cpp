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

int a[510][510];
bool flag[510];
int link[510];

int n,m;
int find(int t)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0&&a[t][i])
		{
			flag[i]=1;
			if(link[i]==-1||find(link[i]))
			{
				link[i]=t;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int i,j;
	int p,x,y,t;
	while(cin>>n>>m)
	{
		if(n==0) break;
//		cin>>m>>t;
n++;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) a[i][j]=0;
		}
		while(m--)
		{
			cin>>x>>y;
			a[x][y]=1;
		}
		for(i=0;i<n;i++) link[i]=-1;
		int ans=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) flag[j]=0;
			if(find(i)) ans++;
		}
		printf("%d\n",ans);
	}
}

