/*
ID: 05272021
LANG: C++
PROG:
*/
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
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
__int64 dp[1010][1010][2];
__int64 inf;
int a[10100];
bool flag[1010][1010][2];
int n;
__int64 dfs(int x,int y,int flg)
{
//	cout<<x<<" "<<y<<" "  <<flg<<endl;;
	if(flag[x][y][flg]) return dp[x][y][flg];
	else
	{
		flag[x][y][flg]=1;
		int cnt1=n-(y-(x+1)+1);
		int cnt2=n-(y-1-x+1);
		if(flg==0)
		{
		//	int cnt=n-()
			 dp[x][y][flg]=MIN(dp[x][y][flg],dfs(x+1,y,0)+(a[x+1]-a[x])*cnt1);
			 dp[x][y][flg]=MIN(dp[x][y][flg],dfs(x+1,y,1)+(a[y]-a[x])*cnt1);
			 
			 dp[x][y][flg]=MIN(dp[x][y][flg],dfs(x,y-1,0)+cnt1*2*(a[y]-a[x]));
			 dp[x][y][flg]=MIN(dp[x][y][flg],dfs(x,y-1,1)+(a[y]-a[y-1]+a[y]-a[x])*cnt1);
			 
		}
		else
		{
			dp[x][y][1]=MIN(dp[x][y][1],dfs(x+1,y,0)+(a[x+1]-a[x]+a[y]-a[x])*cnt1);
			dp[x][y][1]=MIN(dp[x][y][1],dfs(x+1,y,1)+cnt1*2*(a[y]-a[x]));
			
			dp[x][y][1]=MIN(dp[x][y][1],dfs(x,y-1,0)+cnt1*(a[y]-a[x]));
			dp[x][y][1]=MIN(dp[x][y][1],dfs(x,y-1,1)+cnt1*(a[y]-a[y-1]));
		}
		return dp[x][y][flg];
		
	}
}
int main()
{
	int m,i,j;
	inf=1;
	for(i=0;i<50;i++) inf*=2;
	while(cin>>n>>m)	
	{
		
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				 dp[i][j][0]=dp[i][j][1]=inf;
				 flag[i][j][0]=flag[i][j][1]=0;
			}
		}
		int cnt=0;
///a.push_back(m);

		for(i=0;i<n;i++)
		{
			int x;
			cin>>x;
			a[cnt++]=x;
//	a.push_back(x);
		}
		a[cnt++]=m;
		sort(a,a+cnt);
		n=cnt;
		for(i=0;i<n;i++)
		{
			if(a[i]==m) {
				dp[i][i][0]=dp[i][i][1]=0;
			}
			flag[i][i][0]=flag[i][i][1]=1;
		}
	//	dp[i][i][0]=dp[i][i][1]=0;
	//	flag[i][j][0]=flag[i][j][1]=1;
	
		printf("%I64d\n",MIN(dfs(0,n-1,0),dfs(0,n-1,1)));
		/*
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dp[i][j][0]==inf) dp[i][j][0]=-1;
				if(dp[i][j][1]==inf) dp[i][j][1]=-1;
				printf("(%I64d,%I64d) ",dp[i][j][0],dp[i][j][1]);
			}
			printf("\n");
		}
		*/
//		sort(a.begin(),a.end());


		
	}
	return 0;
}
