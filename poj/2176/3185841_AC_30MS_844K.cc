#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[110][110];
void itos(int n,char ans[])
{
    char ch;
    int i=0;
    while(n)
    {
        ch=n%10+'0';
        ans[i++]=ch;
        n/=10;
    }
	reverse(ans,ans+i);
	ans[i]='\0';
}
struct node
{
    int len;
    char s[110];
}q[10010];
void f(int i,int j,int k)
{
    int l,p;
    q[k].len=q[i].len+q[j].len;
    for(l=0;l<q[i].len;l++) q[k].s[l]=q[i].s[l];
    for(p=0;p<q[j].len;p++,l++) q[k].s[l]=q[j].s[p];
    q[k].s[l]='\0';
}
int main()
{
    int n,i,j,k,m;
    int tp;
    int l,p;
    char s[110],ans[20];
//	freopen("f.out","r",stdin);
//	freopen("ff.in","w",stdout);
    while(scanf("%s",&s)!=EOF)
    {
        n=strlen(s);
        for(i=0;i<n;i++)
        {
             dp[i][i]=i;
             q[i].s[0]=s[i];
             q[i].s[1]='\0';
             q[i].len=1;
        }
        m=i;
        for(k=1;k<n;k++)
        {
            for(i=0;i+k<n;i++)
            {
                dp[i][i+k]=m;
                f(dp[i][i],dp[i+1][i+k],m);
              //  m++;
                for(j=i;j<i+k;j++)
                {
                    tp=q[dp[i][j]].len+q[dp[j+1][i+k]].len;
                    if(tp<q[dp[i][i+k]].len) f(dp[i][j],dp[j+1][i+k],m);
                    p=k+1;
                    l=j-i+1;
                    if(p%l==0)
                    {
                        for(p=l;p<=k;p++)
                        {
                            if(s[i+p]!=s[i+p%l]) break;
                        }
                        if(p==k+1)
                        {
                            p=(k+1)/l;
                            itos(p,ans);
                          //  tp+='('+dp[i][j]+')';
                          tp=strlen(ans)+2+q[dp[i][j]].len;
                            if(tp<q[m].len)
                            {
                                q[m].len=tp;
                                strcpy(q[m].s,ans);
                                p=strlen(ans);
                                q[m].s[p++] ='(' ;
                                strcpy(q[m].s+p,q[dp[i][j]].s);
                                p+=q[dp[i][j]].len;
                                q[m].s[p++]=')';
                                q[m].s[p]='\0';
                            }
                        }
                    }
                }
                m++;
            }
        }
        printf("%s\n",q[dp[0][n-1]].s);
    }
    return 0;
}
