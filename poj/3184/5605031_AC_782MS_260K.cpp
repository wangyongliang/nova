#include<iostream>
using namespace std;
#define maxn 11000
#define inf 1000000000
#define ABS(X) ((X)>0?(X):(-(X)))
int dp[2][maxn];
int a[maxn];
int main()
{
    int n,l;
    int i,j,cur,dis;
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<maxn;i++) 
        {
            dp[0][i]=dp[1][i]=-1;            
        }
        if(n==1) printf("0\n");
        else{
        dp[0][0]=ABS(a[0]);
        int d=l/(n-1);
        bool flag=0;
        int r=l%(n-1);
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(j==r+1) break;
                cur=d*i+j;
                if(dp[flag][j]!=-1)
                {
                    dis=dp[flag][j]+ABS(a[i]-cur);

                    if(dp[1-flag][j]==-1||dp[1-flag][j]>dis) dp[1-flag][j]=dis;
                    cur++;
                    dis=dp[flag][j]+ABS(a[i]-cur);

                    if(dp[1-flag][j+1]==-1||dp[1-flag][j+1]>dis) dp[1-flag][j+1]=dis;
                }
                dp[flag][j]=-1;
            }
            dp[flag][j+1]=-1;
            flag=1-flag;
        }
        printf("%d\n",dp[flag][l%(n-1)]);
    }
        
    }
    return 0;
}
