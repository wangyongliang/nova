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

#define maxn 100+(1<<20)
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y)  (x)>(y)?(y):(x)
#define PS system("pause")
int dp[maxn];
int q[maxn];
bool flag[maxn];
int bit[21];
int p[20];
int main()
{
    int i,j;
    bit[0]=1;
    for(i=1;i<21;i++) bit[i]=bit[i-1]*2;
    for(i=0;i<20;i++)
    {
        p[i]       =bit[i];
        if(i-1>=0) p[i]+=bit[i-1];
        if(i+1<20) p[i]+=bit[i+1];
  //      cout<<p[i]<<endl;
    }
    int cur=0;
    //cout<<~cur<<endl;
    for(i=0;i<maxn;i++) dp[i]=maxn;
    for(i=0;i<20;i++)
    {
        cin>>j;
        if(j) cur+=bit[i];
//        cur=cur*2+j;
    }
  //  cout<<cur<<endl;
    dp[cur]=0;
    int st=0;
    int en=1;
    q[st]=cur;
  //  cout<<cur<<endl;
    while(st<en)
    {
        cur=q[st++];
        if(cur==0) break;
        for(i=0;i<20;i++)
        {
            int now=cur&p[i];
            int tp=cur-now;
            now=~now;
            now=now&p[i];
            tp+=now;
         //   cout<<tp<<" "<<dp[tp]<<endl;
            if(dp[tp]>dp[cur]+1)
            {
            //    cout<<tp<<endl;
                dp[tp]=dp[cur]+1;
                q[en++]=tp;
            }
        }
    }
   // cout<<en<<endl;
    cout<<dp[0]<<endl;
 //  while(1);
    return 0;
}
