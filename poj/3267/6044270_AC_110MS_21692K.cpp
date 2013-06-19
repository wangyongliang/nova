#include<iostream>
#include<string.h>
using namespace std;

char str[610][30];
char a[400];
int len[610];
int dp[310][610][30];
int min(int x,int y)
{
    if(x>y) return y;
    else return x;
}
int max(int x,int y)
{
    if(x>y) return x;
    else return y;
}
int main()
{
    int w,i,j,k;
    int n;
    while(scanf("%d%d",&w,&n)!=EOF)
    {
        scanf("%s",a);
        for(i=0;i<w;i++)
        {
            scanf("%s",str[i]);
            len[i]=strlen(str[i]);
            
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<w;j++)
            {
                for(k=0;k<30;k++) dp[i][j][k]=0;
            }
        }
        int max_=0;
        for(i=0;i<w;i++)
        {
            if(a[0]==str[i][0])
            {
                dp[0][i][0]=1;
                if(len[i]==1)
                {
                    max_=1;
                }
            }
        }
       // cout<<max_<<endl;
        for(i=1;i<n;i++)
        {
            for(j=0;j<w;j++)
            {
                dp[i][j][0]=dp[i-1][j][0];
                if(a[i]==str[j][0])
                {
                    dp[i][j][0]=max(dp[i-1][j][0],max_+1);
                }
                for(k=1;k<len[j];k++)
                {
                    dp[i][j][k]=dp[i-1][j][k];
                    if(a[i]!=str[j][k]||dp[i-1][j][k-1]==0) continue;
                    dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j][k-1]+1);
                }
            }
            for(j=0;j<w;j++)
            {
                max_=max(max_,dp[i][j][len[j]-1]);
               /* if(max_>0)
                {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
                */
            }
        }
        printf("%d\n",strlen(a)-max_);
    }
    return 0;
    
}
