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

int a[210][210];
bool flag[210];
int link[210];
int n,m;
int find(int t)
{
	int i;
//	flag[t]=1;
//	printf("find %d \n",t);
//	PS;
	for(i=1;i<=m;i++)	
	{
		if(flag[i]==0&&a[t][i])
		{
			flag[i]			=1;
			if(link[i]==-1||find(link[i]))
			{
				link[i]=t;
				return true;
			}
		}
	}
	return false;
}
int match()
{
	int i;
	for(i=0;i<=m;i++) link[i]=-1;
	int ans=0;
//	system("pause");
	for(i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) flag[j]=0;
		if(find(i)) ans++;
	//	printf("%d\n",ans);
		//PS;
	}
	
	return ans;
}
int main()
{
	int i,j,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++) a[i][j]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&j);
				a[i][j]=1;
			}
		}
		printf("%d\n",match());
	//	for(i=1;i<=m;i++) printf("%d ",link[i]);
//		printf("\n");
	//	PS;
	}
	system("pause");
	return 0;
}
