#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MIN(x,y) (x)>(y)?(y):(x)
#define MAX(x,y) (x)<(y)?(y):(x)
#define ABS(x) (x)>0?(x):-(x)
#define SP(x) setprecision(x)
using namespace std;
#define maxn 1010
int q[maxn*maxn][2] ;
int dp[maxn][maxn][2],a[maxn][maxn];
bool flag[maxn][maxn];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
void bfs(int flg,int x,int y)
{
 //   while(q.size()) q.pop();
    int i,j;
    int st=0;
    int en=1;
    for(i=0;i<maxn;i++)
        {
            for(j=0;j<maxn;j++) flag[i][j]=0,dp[i][j][flg]=0x7ffffff;
        }
    q[0][0]=x;
    q[0][1]=y;
    dp[x][y][flg]=0;
    while(st<en){
        x=q[st][0];
        y=q[st][1];
        for(i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&flag[xx][yy]==0&&a[xx][yy]!=1){
                flag[xx][yy]=1;
                dp[xx][yy][flg]=dp[x][y][flg]+1;
                q[en][0]=xx;
                q[en][1]=yy;
                en++;
            }
        }
        st++;
    }
}

int  main()
{
    int i,j,x1,x2,y1,y2;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) 
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==2) x1=i,y1=j;
                if(a[i][j]==3) x2=i,y2=j;
            }
        }
        bfs(0,x2,y2);
        a[x2][y2]=1;
        bfs(1,x1,y1);
        int ans=0x7fffffff;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(a[i][j]==4){
                    ans=MIN(ans,dp[i][j][0]+dp[i][j][1]);
                }
            }
        }
    //    printf("%d %d\n",dp[0][0][0],dp[0][0][1]);
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
