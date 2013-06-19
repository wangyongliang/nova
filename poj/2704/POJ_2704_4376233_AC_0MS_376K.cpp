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

#define maxn 100
long long dp[maxn][maxn];
int a[maxn][maxn];

int  main()
{
    int n,m;
    int i,j;
    while(cin>>n&&n!=-1){
   //     cout<<"O"<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++) {
                scanf("%1I64d",&a[i][j]);
                dp[i][j]=0;
            }
          // cout<<i<<endl;
        }
        //cout<<"OK"<<endl;
   //     for(i=0;i<n;i++){
  //          for(j=0;j<n;j++) cout<<a[i][j]<<" ";
   //         cout<<endl;
   //     }
        dp[0][0]=1;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==n-1&&j==n-1) continue;
                if(i+a[i][j]<n)  dp[i+a[i][j]][j]+=dp[i][j];
                if(j+a[i][j]<n) dp[i][j+a[i][j]]+=dp[i][j];
            }
        }
//        for(i=0;i<n;i++){
  //          for(j=0;j<n;j++) printf("%I64d ",dp[i][j]);
    //        cout<<endl;
      //  }
        cout<<dp[n-1][n-1]<<endl;
        
    }
    system("pause");
    return 0;
}

