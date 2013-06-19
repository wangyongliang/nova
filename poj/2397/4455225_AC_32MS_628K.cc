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
#define MIN(x,y) ((x)>(y)?(y):(x))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define ABS(x) ((x)>0?(x):-(x))
#define SP(x) setprecision(x)
using namespace std;
#define maxn 1010
int a[maxn];
int dp[maxn][maxn];
void dfs(int n,int m){
  //  cout<<n<<"  "<<m<<endl;
    if(n==0){
      //  return;
         cout<<"U";
        }
    else
    {
        if(m+a[n]<maxn&&dp[n-1][m+a[n]]<=dp[n][m]) 
        {
            dfs(n-1,m+a[n]);
            cout<<"D";
        }
        else 
        {
            dfs(n-1,m-a[n]);
            cout<<"U";
        }
    }
}
int  main()
{
    int t;
    int i,j,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        for(i=0;i<n;i++){
            for(j=0;j<maxn;j++) dp[i][j]=maxn;
        }
        dp[0][a[0]]=a[0];
        for(i=0;i<n;i++){
            for(j=0;j<maxn;j++){
                if(j+a[i+1]<maxn){
                    dp[i+1][j+a[i+1]]=MIN(dp[i+1][j+a[i+1]],MAX(dp[i][j],j+a[i+1]));
                    
                }
                if(j-a[i+1]>=0){
                    dp[i+1][j-a[i+1]]=MIN(dp[i+1][j-a[i+1]],dp[i][j]);
                }
            }
        }
      //  cout<<dp[n-1][0]<<endl;
        if(dp[n-1][0]==maxn) cout<<"IMPOSSIBLE"<<endl;
        else{
            dfs(n-1,0);
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}
