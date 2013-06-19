#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
#define maxn 10000
int dp[maxn][31][2];
int MAX(int x,int y)
{
    if(x>y) return x;
    else return y;
}
int main()
{
    int i,j;
    int n,m;
    scanf("%d%d",&n,&m);
//    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++) dp[i][j][0]=dp[i][j][1]=-10000;
        }
        dp[0][0][0]=0;
        for(i=1;i<=n;i++)
        {
            int tp;
            scanf("%d",&tp);
            tp--;
            for(j=0;j<=m;j++)
            {
                dp[i][j][tp]=MAX(dp[i][j][tp],dp[i-1][j][tp]+1);
                if(j) dp[i][j][tp]=MAX(dp[i][j][tp],dp[i-1][j-1][1-tp]+1);
                if(j) dp[i][j][1-tp]=MAX(dp[i][j][1-tp],dp[i-1][j-1][tp]+1);
                dp[i][j][1-tp]=MAX(dp[i][j][1-tp],dp[i-1][j][1-tp]);
            }
        }
        int ans=0;
        for(i=0;i<=m;i++)
        {
            ans=MAX(ans,dp[n][i][0]);
            ans=MAX(ans,dp[n][i][1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
