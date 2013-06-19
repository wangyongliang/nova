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

using namespace std;
int min(int x,int y)
{
    if(x>y) return y;
    else return x;
}
#define maxn 1010
int dp[maxn][16][16];
int a[maxn][2];
int main()
{
    int i,j,k;
    for(i=0;i<maxn;i++)
    {
        for(j=0;j<16;j++)
        {
            for(k=0;k<16;k++) dp[i][j][k]=0;
        }
    }
//    dp[0][0][0]=0;
    int n=1;
    int x,y;
    while(cin>>x>>y)    
    {
        for(i=0;i<16;i++)
        {
            for(j=0;j<16;j++)
            {
                if(i+1<16&&dp[n-1][i][j]+x>dp[n][i+1][j]) dp[n][i+1][j]=dp[n-1][i][j]+x;
                if(j+1<16&&dp[n-1][i][j]+y>dp[n][i][j+1]) dp[n][i][j+1]=dp[n-1][i][j]+y;
            }
        }
        for(i=0;i<16;i++)
        {
            for(j=0;j<16;j++) if(dp[n-1][i][j]>dp[n][i][j]) dp[n][i][j]=dp[n-1][i][j];
        }
        n++;
    }
    n--;
    cout<<dp[n][15][15]<<endl;
    system("pause");
    return 0;
}
