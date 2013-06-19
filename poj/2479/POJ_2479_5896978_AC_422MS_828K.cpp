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

#define maxn 100010
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y)  ((x)>(y)?(y):(x))
#define PS system("pause")

int dp[maxn][2];
int a[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int i,j;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)        scanf("%d",a+i);
        dp[0][0]=a[0];
        int max=a[0];
        for(i=1;i<n;i++)
        {
            max+=a[i];
            if(max>a[i]) dp[i][0]=max;
            else
            {
                dp[i][0]=a[i];
                max=a[i];
            }
        }
        
        dp[1][1]=a[0]+a[1];
        int max_2=dp[1][1];
        int max_1=MAX(dp[0][0],dp[1][0]);
        int ans=dp[1][1];
        for(i=2;i<n;i++)
        {
            int tp1=max_2+a[i];
            int tp2=max_1+a[i];
            if(tp1>tp2)
            {
                max_2=tp1;
                dp[i][1]=max_2;
            }
            else
            {
                max_2=tp2;
                dp[i][1]=max_2;
            }
            max_1=MAX(max_1,dp[i][0]);
            ans=MAX(ans,dp[i][1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
