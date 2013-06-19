#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include <time.h>

using namespace std;

#define maxn 40000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")
int dp[40000];

int max_deep;
int n;
char flag[30000][200];

#define  size 1000000
int q[size][2];
int st,en;
int check(int x,int y,int deep)
{
	if(x<y) swap(x,y);
	if(x<0) return 0;
	if(y<0) return 0;
	if(dp[x]<deep) return 0;
	if(x<23000&&y<200)
	{
		if(flag[x][y]>deep+1) return 1;
		else return 0;
	}
	else return 0;
}
void insert(int x,int y,int deep)
{
	if(x<y) swap(x,y);
	q[en][0]=x;
	q[en][1]=y;
	flag[x][y]=deep+1;
	if(dp[x]>deep+1) dp[x]=deep+1;
	if(dp[y]>deep+1) dp[y]=deep+1;
	en++;
	en%=size;
}


void bfs()
{

	st=0;
	en=1;
	q[0][0]=1;
	q[0][1]=0;
	dp[1]=0;
	flag[1][0]=0;
	while(st!=en)
	{
		int x=q[st][0];
		int y=q[st][1];
	//	cout<<x<<" "<<y<<endl;
		st++;
		st%=size;
		if(flag[x][y]>dp[n]) continue;
		
		if(check(x*2,y,flag[x][y])) insert(x*2,y,flag[x][y]);
		if(check(x*2,x,flag[x][y])) insert(x*2,x,flag[x][y]);

		if(check(y*2,x,flag[x][y])) insert(y*2,x,flag[x][y]);
		if(check(y*2,y,flag[x][y])) insert(y*2,y,flag[x][y]);

		if(check(x+y,x,flag[x][y])) insert(x+y,x,flag[x][y]);
		if(check(x+y,y,flag[x][y])) insert(x+y,y,flag[x][y]);

		if(check(x-y,x,flag[x][y])) insert(x-y,x,flag[x][y]);
		if(check(x-y,y,flag[x][y])) insert(x-y,y,flag[x][y]);
	}
}
int main()
{
    int i,j;

	
    while(cin>>n)
    {
		for(i=0;i<30000;i++)
		{
			for(j=0;j<500;j++) flag[i][j]=20;
		}
		for(i=0;i<maxn;i++)
		{
			dp[i]=0;
			for(j=0;(1<<j)<=i;j++)
			{
				if((1<<j)&i) dp[i]++;
			}
			dp[i]+=j;
		}
		bfs();
		cout<<dp[n]<<endl;
    }
    return 0;
}
