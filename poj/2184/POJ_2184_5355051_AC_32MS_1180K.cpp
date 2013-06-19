#include<iostream>
#define MAX 9999999
using namespace std;

int dp[200001];
bool a[200001];
int main()
{
    int i,j,k=100000,n,s,f,r,l,sum;
    while(scanf("%d",&n)!=EOF)
    {
          for(i=0;i<=200000;i++)dp[i]=-MAX;
          memset(a,0,sizeof(a));
          dp[k]=0;
          a[k]=1; 
          r=0;l=0;
          for(i=1;i<=n;i++)
          {
              scanf("%d%d",&s,&f); 
              if(s<=0&&f<=0)continue;           
              if(s<0)//从左往右遍历，防止加两次 
              {
                 for(j=l;j<=r;j++)
                 {
                     if(a[j+k]==1&&dp[j+s+k]<dp[j+k]+f)
                     {
                        dp[j+s+k]=dp[j+k]+f;
//                        cout<<j+s<<endl;
//                        cout<<dp[j+k]+f<<endl;
//                        system("pause"); 
                        a[j+s+k]=1;                        
                        }             
                     }
                 l+=s;        
                 }
              else 
              {
                 for(j=r;j>=l;j--)
                 {
                     if(a[j+k]==1&&dp[j+s+k]<dp[j+k]+f)
                     {
                        dp[j+s+k]=dp[j+k]+f;
                        a[j+s+k]=1;
//                        cout<<j+s<<endl;
//                        cout<<dp[j+k]+f<<endl;
//                        system("pause");                                           
                        }                                  
                     }
                 r+=s;      
                 }                
              }
          sum=0;
          for(i=r;i>=0;i--)
          {
              if(a[i+k]==1&&dp[i+k]>=0&&i+dp[i+k]>sum)
              {
                 sum=i+dp[i+k];                               
                 }                  
              }
          printf("%d\n",sum);            
          }
    return 0;
    } 
