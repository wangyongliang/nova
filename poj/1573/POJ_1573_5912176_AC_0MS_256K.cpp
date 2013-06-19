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

using namespace std;

#define maxn 110
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

string str[maxn];
int flag[maxn][maxn];
    int n,m,k;
void dfs(int x,int y,int deep)
{
    //cout<<x<<" "<<y<<endl;
    if(x<0||x>=n||y<0||y>=m)
    {
        cout<<deep<<" step(s) to exit"<<endl;
    }
    else if(flag[x][y]!=-1)
    {
        cout<<flag[x][y]<<" step(s) before a loop of "<<deep-flag[x][y]<<" step(s)"<<endl;
    }
    else
    {
        flag[x][y]=deep;
        if(str[x][y]=='S') dfs(x+1,y,deep+1);
        else if(str[x][y]=='N') dfs(x-1,y,deep+1);
        else if(str[x][y]=='E') dfs(x,y+1,deep+1);
        else dfs(x,y-1,deep+1);
        
    }
        
}
int main()
{

int i,j;
    while(cin>>n>>m>>k)
    {
        if(n+m+k==0) break;
        for(i=0;i<n;i++)
        {
            cin>>str[i];
            for(j=0;j<m;j++)
            {
                flag[i][j]=-1;
            }
            
        }
        dfs(0,k-1,0);
    }
    return 0;
}
