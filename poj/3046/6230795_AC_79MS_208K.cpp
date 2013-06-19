#include<iostream>
#include<stdio.h>

using namespace std;
#define maxn 100010
int dp[maxn];
int sum[maxn];
int mod=1000000;
int cnt[1010];
int main()
{
    int n,A,B,S;
    int i,j;
    while(scanf("%d%d%d%d",&n,&A,&S,&B)!=EOF)
    {
        for(i=1;i<=n;i++) cnt[i]=0;
        for(i=0;i<A;i++)
        {
            scanf("%d",&j);
            cnt[j]++;
        }
        for(i=0;i<=A;i++) 
        {
            dp[i]=sum[i]=0;
        }
        int total=0;
        dp[0]=1;
        sum[0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=total+cnt[i];j++)
            {
                sum[j]=dp[j];
                if(j) sum[j]=(sum[j]+sum[j-1])%mod;
            }
            for(j=total+cnt[i];j>=0;j--)
            {
                dp[j]=sum[j]-(j-cnt[i]-1>=0?sum[j-cnt[i]-1]:0);
                dp[j]=(dp[j]+mod)%mod;
                
            }

            total+=cnt[i];
        }
        int ans=0;
        for(i=S;i<=B;i++) 
        {
//            cout<<dp[i]<<" ";
            ans=(ans+dp[i])%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
