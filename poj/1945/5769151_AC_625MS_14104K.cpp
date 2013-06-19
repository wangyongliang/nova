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
int dfs(int first,int second,int deep)
{

	if(first<second) swap(first,second);
	if(first<0) return 0;
	if(second<0) return 0;
	if(first<30000&&second<200)
	{
		if(flag[first][second]<deep) return 0;
		else flag[first][second]=deep;
	}
	else return 0;
//	if(first==n) return 1;
//	if(second==n) return 1;
//	if(second*second>n) return 0;

  //  if(first>n*2) return 0;
//	if(first*(1<<(max_deep-deep))<n) return 0;
    if(deep==max_deep) return 0;
  //  if(deep>dp[first]+2) return 0;
 //   if(deep>dp[second]+2) return 0;
    if(first==second) return 0;
    if(dp[first]>deep) dp[first]=deep;
    if(dp[second]>deep) dp[second]=deep;
    int tmp;
    if(second>first) swap(first,second);

//	dfs(first,first*2,deep+1);
	if(dfs(first*2,first,deep+1)) return 1;
    if(dfs(first+second,first,deep+1)) return 1;
    if(dfs(first+second,second,deep+1)) return 1;

	if(first==2&&second==1)
	{
		printf("");
	}
	if(dfs(first*2,second,deep+1)) return 1;
	if(dfs(second*2,first,deep+1)) return 1;
	if(dfs(second*2,second,deep+1)) return 1;

    if(dfs(first-second,second,deep+1)) return 1;
    if(dfs(first-second,first,deep+1)) return 1;
    return 0;
    
}
#define  size 1000000
int q[size][2];
int st,en;
int check(int x,int y,int deep)
{
	if(x<y) swap(x,y);
	if(x<0) return 0;
	if(y<0) return 0;
	if(dp[x]<deep) return 0;
	if(x<30000&&y<200)
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
	int st=clock();

//	bfs();
	int en=clock();
//	cout<<"OK"<<endl;
//	cout<<"time is :"<<en-st<<endl;
    while(cin>>n)
    {
		bfs();
		cout<<dp[n]<<endl;
		continue;
        for(max_deep=0;max_deep<dp[n];max_deep++)
		{
			if(dfs(1,0,0)) break;
		}
		cout<<max_deep<<endl;
    }
    return 0;
}
